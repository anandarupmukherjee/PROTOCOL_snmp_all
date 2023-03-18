# snmp_all
implementations of snmp on python (raspberry pi), Arduino (ESP32), and docker container


<h1>1) SNMP_RPI.py</h1>

This code uses the PySNMP library to send SNMP traps to an SNMP manager at a specified IP address every 5 seconds. The community_string variable specifies the SNMP community string to use, and the presence_status_oid variable specifies the OID for the device presence status.

Within the while loop, an SNMP trap is sent to the manager using the sendNotification function from the PySNMP library. The NotificationType object specifies the OID for the trap, and the addVarBinds method is used to add the device presence status OID and a value of 'present' to the trap.

Any errors that occur during the sending of the trap are printed to the console, and the loop waits for 5 seconds before sending the next trap. This code can be run on a Raspberry Pi to implement a device presence protocol using SNMP.


<h1>2) SNMP_ESP32.ino</h1>
