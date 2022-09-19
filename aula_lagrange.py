def lagrange(x, count, pontos):
	L = 1
	P = 0

	#Calculo do polinômio de Lagrange
	for i in range(count):
		for j in range(count):
			if j != i:
				L = L*(x-pontos[0][j])/(pontos[0][i]-pontos[0][j])
		P += (pontos[1][i]*L)
		L = 1
	return P