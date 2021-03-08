# Daemonizer

A singleton class designed for easily converting your Qt program into a daemon.

This class only deals with new style daemons, because why write in the old
style, when there's a new style?

Just instantiate the singleton and call init.
Optionally define one of the 3 callbacks before calling init if you want
something other than the default behavior for the Unix signals.

Daemonizer::init() must be called in main after QCoreApplication is 
instantiated, but before QCoreApplication::exec() is called.

## Installing

After cloning, just run `sudo ./install.sh`
Also that script gives you a good idea of how to set up your own daemon.
It's short and easy to follow.
Make a script like it to set up your own daemon and you can run it to update
changes.

## Manual Install Notes:

The *.service file will need to be created or copied and edited for your own
program. 
Replace "daemontest" with the name of your program.
Make sure your Qt program is using at least C++17. You might need to edit the
*.pro file.

 - Make sure file names in daemontest.service match the name of the binary.
 - sudo chmod 644 daemontest.service
 - sudo cp daemontest.service /etc/systemd/system/
 - Config files if needed:
 - sudo cp whatever.conf /etc/daemontest
 - Copy the binary:
 - sudo cp daemontest /usr/bin
 - Run `sudo systemctl daemon-reload`
 - sudo systemctl start daemontest

## Fedora SysLog notes:

To view:

`journalctl -b`

(-b is for the current boot logs only)

Use vim "/" to search for daemontest, then navigate entries

OR

Use the "logs" application for easy searching and scrolling.
Viewed log only updates when search term changes.

