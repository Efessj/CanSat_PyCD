import csv
import re

values = [['paquete', 'presión', 'temperatura', 'intensidad', 'latitud', 'longitud']]

#n presió: nnnnnnn temperatura: nn.nn\n corriente: nn.nn latitud: nnnn longitud: nnnn
def ReadData():
    with open('data.txt', 'r', encoding="utf-8") as dataFile:
        return dataFile.read()

def Convert():
    for i in data.split('\n'):
        values.append(i.split(' '))


def Removetxt(txt):
    for i in values:
        if txt in i: i.remove(txt)


def SaveData():
    with open("datos.csv", mode="w", newline="", encoding="utf-8") as file:
        writer = csv.writer(file) 
        writer.writerows(values)
    
data = re.sub(r'\.', ',', ReadData())

Convert()

Removetxt('presio:')
Removetxt('temperatura:')
Removetxt('corriente:')
Removetxt('latitud:')
Removetxt('longitud:')

SaveData()

print('Archivo CSV creado con exito')
