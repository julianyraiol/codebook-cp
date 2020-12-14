import statistics

real_madri = [7, 9, 9, 9, 10, 11, 12, 12, 15, 15]
psg = [9, 10, 12, 13, 14, 14, 16, 18, 23, 37]


def estatistica_metodos(lista):
    moda = statistics.mode(lista)
    mediana = statistics.median(lista)
    media = statistics.mean(lista)
    desvio = statistics.pstdev(lista)
    variancia = statistics.pvariance(lista)
    quartil = statistics.quantiles(lista)
    print("MODA: ", moda, "\nMEDIANA: ", mediana, " \nMEDIA: ", media, "\nDESVIO PADRÃO: ", desvio, "\nVARIANCIA: ", variancia)
    print("QUARTIL: ", quartil)

# questão 1
print("REAL MADRI")
estatistica_metodos(real_madri)

print("\n\nPSG")
estatistica_metodos(psg)
