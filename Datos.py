import csv
import re

values = [['paquete', 'presión', 'temperatura']]

#n presió: nnnnnnn temperatura: nn.nn\n
def ReadData():
    with open('data.txt', 'r', encoding="utf-8") as dataFile:
        return dataFile.read()

def Convert(txt1, txt2):
    for i in data.split('\n'):
        values.append(i.split(' '))

    for i in values:
        if txt1 in i: i.remove(txt1)
        if txt2 in i: i.remove(txt2)

def SaveData():
    with open("datos.csv", mode="w", newline="", encoding="utf-8") as file:
        writer = csv.writer(file) 
        writer.writerows(values)
    
data = re.sub('\.', ',', ReadData())

Convert('presió:', 'temperatura:')

print('Archivo CSV creado con exito')
