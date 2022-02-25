This exe limits the charge threshold to 60%. Use Windows Task Scheduler to import the xml to run at startup/unlocking workstation. Remember to change the path to the exe. To disable the threshold, simply restart the computer with the task disabled. No more need for the UWP app, YEAH!

Currently, the XML provided triggers when the laptop starts up or is unlocked. To trigger on switching to AC power, if you have event logging enabled, add the following trigger in Windows Task Scheduler:

Begin the task: On an event
Basic
Log: System
Source: Kernel-Power
Event ID: 105
Click Okay

Change to Conditions Tab - In the "Power" section
Enable checkbox: Start the task only if the computer is on AC power.
