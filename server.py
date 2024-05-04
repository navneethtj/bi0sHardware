from pymodbus.server.sync import StartTcpServer
from pymodbus.datastore import ModbusSequentialDataBlock, ModbusSlaveContext, ModbusServerContext

def run_server():
    block_size = 100
    di_block = ModbusSequentialDataBlock(0, [0] * block_size)
    co_block = ModbusSequentialDataBlock(0, [0] * block_size)
    hr_block = ModbusSequentialDataBlock(0, [0] * block_size)
    ir_block = ModbusSequentialDataBlock(0, [0] * block_size)

    slaves = {0x01: ModbusSlaveContext(di=di_block, co=co_block, hr=hr_block, ir=ir_block)}

    context = ModbusServerContext(slaves=slaves, single=False)

    StartTcpServer(context, address=("127.0.0.1", 5020))

    print("Values received and sent by the server:")
    print("DI:", context[0x01].di)
    print("CO:", context[0x01].co)
    print("HR:", context[0x01].hr)
    print("IR:", context[0x01].ir)

if __name__ == "__main__":
    print("Modbus server started on localhost port 5020")
    run_server()