from Lagrange import lagrange
from Neville import neville 

#Nome do arquivo com os pontos
nome = input("Digite o nome do arquivo onde os dados estão contidos: ")

pontos = [[],[]]
arq = open(nome, "r")
count = 0

#Alocação dos dados em uma matriz
for line in arq:
	cont = 0
	for i in line.split():
		pontos[cont].append(float(i))
		cont+=1
	count+=1
arq.close()

#Entrada dos dados de integração
print("\nEntre o intervalo em que a interpolação será feita: ")
linf = float(input("Limite inferior: "))
lsup = float(input("Limite superior: "))

m = float(input("\nNúmero de pontos a serem calculados: "))
dx = (lsup-linf)/m

nome = input("\nNome do arquivo para salvar os dados: ")

#Escolha do método de interpolação
met = input("Método de interpolação (lagrange/neville): ")

if met == "lagrange":
	#Interpolação pelo método de Lagrange
	arq = open(nome, "w")
	x = linf
	while x < lsup:
		P = lagrange(x, count, pontos)
		arq.write("%f\t%f\n" %(x,P))
		x += dx
	arq.close()

if met == "neville":
	#Interpolação pelo método de Neville
	arq = open(nome, "w")
	x = linf
	while x < lsup:
		Neville = [[]for i in range(count)]
		for i in range(count):
			Neville[0].append(pontos[1][i])
		Neville = neville(count, pontos, x, Neville)
		arq.write("%f\t%f\n" %(x, Neville[count-1][0]))
		x+=dx
	arq.close()

print ("\n\n")