from Bissec import bissec 
from Iterativo import iterativo
from Newton import newton 
from math import fabs

cont = 0
zeros = []
teste = False

print ("\t----Zeros de funcoes----\n\n")

#Entrada do intervalo de busca
print ("Qual será o intervalo de busca das raizes?\n")
linf = float(input("Digite o limite inferior: "))
lsup = float(input("Digite o limite superior: "))

#Entrada do método desejado
while teste == False:
	met = input("Qual devera ser o metodo de procura? (bisseccao/iteracao/newton)\n")
	if met != "bisseccao" and met != "newton" and met != "iteracao":
		print ("Entrada invalida! Digite um nome valido de metodo!\n")
	else: teste = True

if met == "bisseccao":
	#Chamada da função de bissecção
	bissec(linf,lsup)

elif met == "newton":
	i = linf

	#Laço para executar o método de Newton
	while i <= lsup:
		x = newton(i)
		cont = 0

		#Adição das raízes válidas a um vetor
		if x <= lsup and x >= linf:
			for j in zeros:
				if fabs(x-j) < 10**-10:
					cont +=1
			if cont == 0:
				zeros.append(x)
		i += 1

	if len(zeros) == 0:
		printf("\nNao ha raizes no intervalo escolhido!\n")
	else:
		zeros.sort()
		print ("\nAs raizes da funcao no intervalo escolhido sao:\n")
		for i in range(len(zeros)):
			print ("%lf\n" %zeros[i])

elif met == "iteracao":
	i = linf

	#Laço para executar o método de iteração
	while i <= lsup:
		x = iterativo(i)
		cont = 0
		#Adição das raízes válidas a um vetor
		if x <= lsup and x >= linf:
			for j in zeros:
				if fabs(x-j) < 10**-10:
					cont +=1
			if cont == 0:
				zeros.append(x)
		i+=1
		
	if len(zeros) == 0:
		print ("\nNao ha raizes no intervalo escolhido ou nao foi possivel acha-la com este metodo!\n")
	else:
		zeros.sort()
		print ("\nAs raizes da funcao no intervalo escolhido sao:\n")
		for i in range(len(zeros)):
			print ("%lf\n" %zeros[i])
print ("\n\n")