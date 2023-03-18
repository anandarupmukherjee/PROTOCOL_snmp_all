#include <WiFi.h>
#include <WiFiUdp.h>
#include <SNMP.h>

// Set the SNMP community string and IP address of the SNMP manager
const char* community_string = "public";
IPAddress manager_ip(192, 168, 1, 100);

// Define the OID for the device presence status
OID presence_status_oid = {1, 3, 6, 1, 2, 1, 1, 8, 0};

// Set up the UDP client for sending SNMP traps
WiFiUDP udp_client;

void setup() {
  // Connect to WiFi
  WiFi.begin("SSID", "PASSWORD");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }

  // Set up the SNMP library
  SNMP.begin();
}

void loop() {
  // Send an SNMP trap to the manager with the device presence status
  int result = SNMP.trap(
    IPAddress(udp_client.remoteIP()),
    community_string,
    presence_status_oid,
    OctetString("present")
  );

  // Print any errors that occur
  if (result < 0) {
    Serial.println("Error sending SNMP trap");
  }

  // Wait for 5 seconds before sending the next trap
  delay(5000);
}
