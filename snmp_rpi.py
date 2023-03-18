import time
from pysnmp.hlapi import *

# Set the SNMP community string and IP address of the SNMP manager
community_string = 'public'
manager_ip = '192.168.1.100'

# Define the OID for the device presence status
presence_status_oid = ObjectIdentity('1.3.6.1.2.1.1.8.0')

# Loop to send SNMP traps every 5 seconds
while True:
    # Send an SNMP trap to the manager with the device presence status
    error_indication, error_status, error_index, var_binds = next(
        sendNotification(
            SnmpEngine(),
            CommunityData(community_string),
            UdpTransportTarget((manager_ip, 162)),
            ContextData(),
            'trap',
            NotificationType(
                ObjectIdentity('1.3.6.1.6.3.1.1.5.1')
            ).addVarBinds(
                (presence_status_oid, OctetString('present'))
            )
        )
    )
    
    # Print any errors that occur
    if error_indication:
        print('Error sending SNMP trap: %s' % error_indication)
    
    # Wait for 5 seconds before sending the next trap
    time.sleep(5)
