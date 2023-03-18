FROM ubuntu:latest

RUN apt-get update && \
    apt-get install -y snmp snmpd

COPY snmpd.conf /etc/snmp/

CMD ["snmpd", "-f", "-Lo", "-Ducd-snmp/pass", "-Ducd-snmp/v3-mib-user", "-Ducd-snmp/dlmod"]
