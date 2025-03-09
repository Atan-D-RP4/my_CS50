# A Simple Hex-Code generator for 8085 Assembly Language
import argparse
import tabulate

opcodes = {

    "MOV B, B": 0x40, "MOV C, B": 0x48, "MOV D, B": 0x50, "MOV E, B": 0x58, "MOV H, B": 0x60, "MOV L, B": 0x68, "MOV M, B": 0x70, "MOV A, B": 0x78,
    "MOV B, C": 0x41, "MOV C, C": 0x49, "MOV D, C": 0x51, "MOV E, C": 0x59, "MOV H, C": 0x61, "MOV L, C": 0x69, "MOV M, C": 0x71, "MOV A, C": 0x79,
    "MOV B, D": 0x42, "MOV C, D": 0x4A, "MOV D, D": 0x52, "MOV E, D": 0x5A, "MOV H, D": 0x62, "MOV L, D": 0x6A, "MOV M, D": 0x72, "MOV A, D": 0x7A,
    "MOV B, E": 0x43, "MOV C, E": 0x4B, "MOV D, E": 0x53, "MOV E, E": 0x5B, "MOV H, E": 0x63, "MOV L, E": 0x6B, "MOV M, E": 0x73, "MOV A, E": 0x7B,
    "MOV B, H": 0x44, "MOV C, H": 0x4C, "MOV D, H": 0x54, "MOV E, H": 0x5C, "MOV H, H": 0x64, "MOV L, H": 0x6C, "MOV M, H": 0x74, "MOV A, H": 0x7C,
    "MOV B, L": 0x45, "MOV C, L": 0x4D, "MOV D, L": 0x55, "MOV E, L": 0x5D, "MOV H, L": 0x65, "MOV L, L": 0x6D, "MOV M, L": 0x75, "MOV A, L": 0x7D,
    "MOV B, M": 0x46, "MOV C, M": 0x4E, "MOV D, M": 0x56, "MOV E, M": 0x5E, "MOV H, M": 0x66, "MOV L, M": 0x6E,                   "MOV A, M": 0x7E,
    "MOV B, A": 0x47, "MOV C, A": 0x4F, "MOV D, A": 0x57, "MOV E, A": 0x5F, "MOV H, A": 0x67, "MOV L, A": 0x6F, "MOV M, A": 0x77, "MOV A, A": 0x7F,

    "ADD B": 0x80, "ADD C": 0x81, "ADD D": 0x82, "ADD E": 0x83, "ADD H": 0x84, "ADD L": 0x85, "ADD M": 0x86, "ADD A": 0x87,
    "ADC B": 0x88, "ADC C": 0x89, "ADC D": 0x8A, "ADC E": 0x8B, "ADC H": 0x8C, "ADC L": 0x8D, "ADC M": 0x8E, "ADC A": 0x8F,
    "SUB B": 0x90, "SUB C": 0x91, "SUB D": 0x92, "SUB E": 0x93, "SUB H": 0x94, "SUB L": 0x95, "SUB M": 0x96, "SUB A": 0x97,
    "SBB B": 0x98, "SBB C": 0x99, "SBB D": 0x9A, "SBB E": 0x9B, "SBB H": 0x9C, "SBB L": 0x9D, "SBB M": 0x9E, "SBB A": 0x9F,
    "ANA B": 0xA0, "ANA C": 0xA1, "ANA D": 0xA2, "ANA E": 0xA3, "ANA H": 0xA4, "ANA L": 0xA5, "ANA M": 0xA6, "ANA A": 0xA7,
    "XRA B": 0xA8, "XRA C": 0xA9, "XRA D": 0xAA, "XRA E": 0xAB, "XRA H": 0xAC, "XRA L": 0xAD, "XRA M": 0xAE, "XRA A": 0xAF,
    "ORA B": 0xB0, "ORA C": 0xB1, "ORA D": 0xB2, "ORA E": 0xB3, "ORA H": 0xB4, "ORA L": 0xB5, "ORA M": 0xB6, "ORA A": 0xB7,
    "CMP B": 0xB8, "CMP C": 0xB9, "CMP D": 0xBA, "CMP E": 0xBB, "CMP H": 0xBC, "CMP L": 0xBD, "CMP M": 0xBE, "CMP A": 0xBF,
    "INR B": 0x04, "INR C": 0x0C, "INR D": 0x14, "INR E": 0x1C, "INR H": 0x24, "INR L": 0x2C, "INR M": 0x34, "INR A": 0x3C,
    "DCR B": 0x05, "DCR C": 0x0D, "DCR D": 0x15, "DCR E": 0x1D, "DCR H": 0x25, "DCR L": 0x2D, "DCR M": 0x35, "DCR A": 0x3D,
    "MVI B": 0x06, "MVI C": 0x0E, "MVI D": 0x16, "MVI E": 0x1E, "MVI H": 0x26, "MVI L": 0x2E, "MVI M": 0x36, "MVI A": 0x3E,

    "LXI B" : 0x01, "LXI D" : 0x11, "LXI H" : 0x21, "LXI SP"  : 0x31,
    "INX B" : 0x03, "INX D" : 0x13, "INX H" : 0x23, "INX SP"  : 0x33,
    "DCX B" : 0x0B, "DCX D" : 0x1B, "DCX H" : 0x2B, "DCX SP"  : 0x3B,
    "DAD B" : 0x09, "DAD D" : 0x19, "DAD H" : 0x29, "DAD SP"  : 0x39,
    "LDAX B": 0x0A, "LDAX D": 0x1A, "LDAX H": 0x2A, "LDAX SP" : 0x3A,
    "STAX B": 0x02, "STAX D": 0x12, "SHLD"  : 0x22, "STA"     : 0x32,
    "PUSH B": 0xC5, "PUSH D": 0xD5, "PUSH H": 0xE5, "PUSH PSW": 0xF5,
    "POP B" : 0xC1, "POP D" : 0xD1, "POP H" : 0xE1, "POP PSW" : 0xF1,

    "ADI": 0xC6, "RST 0": 0xC7, "RLC": 0x07, "HLT": 0x76,
    "ACI": 0xCE, "RST 1": 0xCF, "RRC": 0x0F, "NOP": 0x00,
    "SUI": 0xD6, "RST 2": 0xD7, "RAL": 0x17, "RIM": 0x20,
    "SBI": 0xDE, "RST 3": 0xDF, "RAR": 0x1F, "SIM": 0x30,
    "ANI": 0xE6, "RST 4": 0xE7, "DAA": 0x27, "DI" : 0xF3,
    "XRI": 0xEE, "RST 5": 0xEF, "CMA": 0x2F, "EI" : 0xFB,
    "ORI": 0xF6, "RST 6": 0xF7, "STC": 0x37, "IN" : 0xDB,
    "CPI": 0xFE, "RST 7": 0xFF, "CMC": 0x3F, "OUT": 0xD3,

    "JMP": 0xC3, "CALL": 0xCD, "RET": 0xC9,
    "JZ" : 0xCA, "CZ"  : 0xCC, "RZ" : 0xC8,
    "JNZ": 0xC2, "CNZ" : 0xC4, "RNZ": 0xC0,
    "JC" : 0xDA, "CC"  : 0xDC, "RC" : 0xD8,
    "JNC": 0xD2, "CNC" : 0xD4, "RNC": 0xD0,
    "JPE": 0xEA, "CPE" : 0xEC, "RPE": 0xE8,
    "JPO": 0xE2, "CPO" : 0xE4, "RPO": 0xE0,
    "JM" : 0xFA, "CM"  : 0xFC, "RM" : 0xF8,
    "JP" : 0xF2, "CP"  : 0xF4, "RP" : 0xF0,

    "LHLD": 0x2A, "SHLD": 0x22, "LDA" : 0x3A, "STA" : 0x32,
    "XCHG": 0xEB, "XTHL": 0xE3, "PCHL": 0xE9, "SPHL": 0xF9,
}

reg = ["A", "B", "C", "D", "E", "H", "L", "M"]

parser = argparse.ArgumentParser(description="A Simple Hex-Code generator for 8085 Assembly Language")
parser.add_argument("file", help="The file to be compiled")
parser.add_argument("-o", "--output", help="The output file")
args = parser.parse_args()


def get_file():
    try:
        with open(args.file, "r") as file:
            return file.read()
    except FileNotFoundError:
        print("File not found")
        exit(1)


def parse_file(file):
    # List of all two byte instructions
    three_byte_instructions = [
       "LXI", "LDA", "STA", "LHLD", "SHLD", "JMP", "JC",
       "JNC", "JZ", "JNZ", "JP", "JM", "JPE", "JPO",
       "CALL", "CC", "CNC", "CZ", "CNZ", "CP", "CM",
       "CPE", "CPO", "ADI", "ACI", "SUI", "SBI", "ANI",
       "XRI", "ORI", "CPI"
    ]

    lines = []
    labels = {}
    address = 0x8000
    line_num = 1

    for line in file.split("\n"):
        data = False
        line = line.strip()

        if not line or line.startswith(";") or line.startswith("#"):
            continue
        if ":" in line:
            label, inst = line.split(":")
            labels[label] = line_num
            line = inst.strip()
        if line:
            mnemonic = line.split()[0]
            operands = []
            for operand in line.split()[1:]:
                operand = operand.replace(",", "")
                if operand not in reg:
                    try:
                        if int(operand, 16) > 0xFF:
                            low = str(operand)[-2:]
                            high = str(operand)[:-2]
                            operands.append(low)
                            operands.append(high)
                        else:
                            data = True
                            operands.append(operand)
                    except ValueError:
                        operands.append(operand)
                else:
                    operands.append(operand)
        lines.append((line_num, mnemonic, operands))
        line_num += 1
    print(tabulate.tabulate(lines, headers=["Line", "Instruction", "Operands"]))
    print(labels)
    return lines, labels




def compile(file):
    lines, labels = parse_file(file)
    compiled = []
    address = 0x8000 # start

    for line, mnemonic, operand in lines:
        if len(operand) > 2:
            print("Invalid number of operands")
            exit(1)

    ...


    print("Compiled")
    return compiled


def main():
    file = get_file()
    compiled = compile(file)

    if args.output:
        with open(args.output, "w") as file:
            print(tabulate.tabulate(compiled, headers=["Address", "Code"]))
    else:
        for address, code in compiled:
            print(f"{address} {code}")

if __name__ == '__main__':
    main()
