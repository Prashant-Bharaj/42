*This project has been created as part of the 42 curriculum by prasingh*

--- 
## 📌 Overview

**Born2beRoot** is 

You will create a **fully functional virtual machine** using **Debian** (or Rocky Linux), configure secure services, enforce strict password policies, set up firewall rules, and create an automated monitoring script.

This README documents the configuration, rationale, implementation steps, and all commands used to build the VM exactly according to the 42 School subject.

---
## Descritpion
This projects aim is to create a debian server using virtual box, which should follow specific requirements.

## Instructions
- For this project two different flavours of linux were allowed Debian and Rocky.
    Debian was recommended in the 42 subject itself and it has relavently less image size ~784 MB as compared to Rocky, which was around 1,6 GB. So for this project, the Debian distro has been choosed. 
- For portability the vdi file was stored in the extrnal hard-drive so that entire work can be carried with the harddrive and work both remotely and within the 42 campus.
-  

## Resources 
- 42 Subject
- Debian file: https://www.debian.org/distrib/
- VirtualBox - ()
- 

• An“Instructions” section containing any relevant information about compilation,
installation, and/or execution.
• A “Resources” section listing classic references related to the topic (documen
tation, articles, tutorials, etc.), as well as a description of how AI was used —
specifying for which tasks and which parts of the project.
➠ Additional sections may be required depending on the project (e.g., usage
examples, feature list, technical choices, etc.)
Any required additions will be explicitly listed below.
• A Project description section must also explain the choice of operating system
(Debian or Rocky), with their respective pros and cons. It must indicate the main
design choices made during the setup (partitioning, security policies, user manage
ment, services installed) as well as a comparison between:
◦ Debian vs Rocky Linux
◦ AppArmor vs SELinux
◦ UFWvs firewalld
◦ VirtualBox vs UTM

---


---

# 🖥️ 1. Virtual Machine Setup

### **Chosen OS:**

✔ **Debian 12+ (Bookworm / Trixie)**

### **Virtualization:**

✔ **VirtualBox**
✔ VM stored on an **external hard drive** to allow working from home and 42 campus on the same machine
✔ VM safely shutdown using `shutdown -h now` before unplugging the external disk

### **Partitioning (Mandatory + LVM)**

| Partition      | Type        | Use                    | Encrypted                    |
| -------------- | ----------- | ---------------------- | ---------------------------- |
| /boot          | ext4        | Bootloader             | ❌ No (must NOT be encrypted) |
| LUKS container | crypto_LUKS | Encrypted block device | ✔ Yes                        |
| LVM VG         | LVM         | Contains LVs           | ✔ Yes                        |
| LV root        | ext4        | /                      | ✔ Yes                        |
| LV home        | ext4        | /home                  | ✔ Yes                        |
| LV swap        | swap        | swap area              | ✔ Yes                        |
| LV var         | ext4        | /var                   | ✔ Yes                        |
| LV tmp         | ext4        | /tmp                   | ✔ Yes                        |

This layout respects the security requirements of the 42 subject.
LVM + LUKS ensures flexibility + strong encryption.

---

# 🔐 2. Security Configuration

## 2.1. SSH

✔ Installed OpenSSH
✔ SSH runs **only on port 4242**
✔ Root login disabled
✔ Only the student user has sudo access
✔ SSH secured with UFW

---

## 2.2. UFW Firewall

✔ Only port **4242/tcp** allowed
✔ All incoming traffic denied by default
✔ Outgoing traffic allowed
✔ Firewall enabled at startup

---

## 2.3. Sudo Configuration

Using `visudo`:

* Password attempts limited: `passwd_tries=3`
* Custom error message: `"Try harder!"`
* Logging to `/var/log/sudo.log`
* TTY required for sudo
* Secure PATH enforced

This enhances auditing and prevents automated escalation attempts.

---

# 🔑 3. Password & Authentication Policies

## 3.1. Password Strength (PAM)

Enforced via `/etc/pam.d/common-password`:

* Minimum length: **10**
* At least **1 uppercase**
* At least **1 lowercase**
* At least **1 digit**
* At least **1 special character**
* 3 retry attempts

Uses: `libpam-pwquality`.

---

## 3.2. Password Expiration (login.defs)

```
PASS_MAX_DAYS   30
PASS_MIN_DAYS   2
PASS_WARN_AGE   7
```

---

# 🛡️ 4. AppArmor

✔ AppArmor enabled and loaded
✔ Kernel boot parameters configured:

```
apparmor=1 security=apparmor
```

✔ Profiles loaded and enforcing mode active
✔ Verified via:

```
sudo aa-status
```

AppArmor provides Mandatory Access Control (MAC) protection on services and binaries.

---

# 🧩 5. Monitoring Script (`monitoring.sh`)

A script placed in `/usr/local/bin/monitoring.sh` that broadcasts system information using `wall`.
It includes:

* Architecture
* vCPU count
* Physical CPU
* Memory usage
* Disk usage
* CPU load
* Last boot time
* LVM usage
* TCP connections
* Logged-in users
* IP address
* MAC address

Cron runs the script **every 10 minutes**.

Cron entry:

```
*/10 * * * * /usr/local/bin/monitoring.sh
```

---

# 🗂️ 6. Evaluation Checklist

✔ Correct partitioning (LVM + encrypted volumes)
✔ hostname: `<login>42`
✔ SSH listening on port 4242
✔ UFW active and only 4242 allowed
✔ sudo correctly configured
✔ password policy enforced
✔ password expiration rules enforced
✔ AppArmor active & enforcing
✔ monitoring.sh working and broadcasts output
✔ cron runs the script every 10 minutes
✔ VM shuts down cleanly
✔ signature.txt contains SHA1 hash of `.vdi`

---

# 📄 7. Submission (signature.txt)

Locate the `.vdi` file:

Windows:

```
%HOMEDRIVE%%HOMEPATH%\VirtualBox VMs\born2beroot\
```

Generate SHA1:

```
certUtil -hashfile born2beroot.vdi sha1
```

Paste hash into `signature.txt` and push to Git repository.

---

# 🧰 8. Important Commands (Full Setup Sequence)

```md
## 🧩 Important Commands (Full Configuration Sequence)

### 1. Update system
sudo apt update && sudo apt upgrade -y

### 2. SSH configuration
sudo apt install openssh-server -y
sudo nano /etc/ssh/sshd_config   # Set Port 4242 and disable root
sudo systemctl restart ssh
sudo systemctl enable ssh
ss -tunlp | grep ssh

### 3. Firewall
sudo apt install ufw -y
sudo ufw allow 4242/tcp
sudo ufw enable
sudo ufw status verbose

### 4. Sudo configuration
sudo apt install sudo -y
sudo usermod -aG sudo <login>
sudo visudo  # Add passwd_tries, badpass_message, logfile, secure_path, requiretty

### 5. Password Policy (PAM)
sudo apt install libpam-pwquality -y
sudo nano /etc/pam.d/common-password
# Add pam_pwquality rule

### 6. Password expiration
sudo nano /etc/login.defs
# Set PASS_MAX_DAYS 30, etc.

### 7. AppArmor
sudo nano /etc/default/grub
# Add apparmor=1 security=apparmor
sudo update-grub
sudo reboot
sudo aa-status

### 8. monitoring.sh
sudo nano /usr/local/bin/monitoring.sh
sudo chmod +x /usr/local/bin/monitoring.sh
sudo /usr/local/bin/monitoring.sh

### 9. Cron
sudo crontab -e
# */10 * * * * /usr/local/bin/monitoring.sh

### 10. Shutdown
sudo shutdown -h now
```

---

# 🎓 Final Notes

This project significantly strengthens your understanding of:

* Linux server security
* Mandatory Access Control
* Encryption (LUKS)
* Virtualization
* System monitoring
* Administrative automation
* Service configuration
* Firewall management