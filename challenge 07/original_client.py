from pymodbus.client.sync import ModbusTcpClient
import time

def run_client():
    client = ModbusTcpClient('127.0.0.1', port=5020)

    values_to_write = [10, 20, 30, 40, 50]
    client.write_registers(0, values_to_write, unit=0x01)
    print("Values written to server registers by the client:", values_to_write)

    client.close()
    print("Waiting for 10 seconds before reading back the values...")
    time.sleep(10)

    client = ModbusTcpClient('127.0.0.1', port=5020)

    read_values = client.read_holding_registers(0, 5, unit=0x01)
    print("Values read from server registers by the client:", read_values.registers)

    client.close()

if __name__ == "__main__":
    run_client()