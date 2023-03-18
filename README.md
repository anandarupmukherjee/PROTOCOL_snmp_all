# snmp_all
implementations of snmp on python (raspberry pi), Arduino (ESP32), and docker container


<h1>1) SNMP_RPI.py</h1>

This code uses the PySNMP library to send SNMP traps to an SNMP manager at a specified IP address every 5 seconds. The community_string variable specifies the SNMP community string to use, and the presence_status_oid variable specifies the OID for the device presence status.

Within the while loop, an SNMP trap is sent to the manager using the sendNotification function from the PySNMP library. The NotificationType object specifies the OID for the trap, and the addVarBinds method is used to add the device presence status OID and a value of 'present' to the trap.

Any errors that occur during the sending of the trap are printed to the console, and the loop waits for 5 seconds before sending the next trap. This code can be run on a Raspberry Pi to implement a device presence protocol using SNMP.


<h1>2) SNMP_ESP32.ino</h1>

This code uses the Arduino SNMP library to send SNMP traps to an SNMP manager at a specified IP address every 5 seconds. The community_string variable specifies the SNMP community string to use, and the presence_status_oid variable specifies the OID for the device presence status.

Within the loop function, an SNMP trap is sent to the manager using the SNMP.trap function from the SNMP library. The IPAddress object specifies the IP address of the manager, and the OctetString object is used to specify the value of 'present' for the device presence status.

Any errors that occur during the sending of the trap are printed to the serial console, and the loop waits for 5 seconds before sending the next trap. This code can be run on an ESP32 to implement a device presence protocol using SNMP. Note that you will need to replace "SSID" and "PASSWORD" with the name and password of your WiFi network.


<h1>3) SNMP DOCKERFILE</h1>
