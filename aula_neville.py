def neville(count, pontos, x, Neville):
	j = 1

	#Calculo da matriz de Neville
	while j < count:
		i = 0
		while i < (count-j):
			Neville[j].append((((x-pontos[0][j+i])*Neville[j-1][i])-((x-pontos[0][i])*Neville[j-1][i+1]))/(pontos[0][i]-pontos[0][i+j]))
			i += 1
		j+=1

	return Neville