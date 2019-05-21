# Makefile du projet nb_prem / ESI 2019 / 1CPI / ALSDD 
# Sous Linux faites make pour compiler le tout et generer l'executable 'prime'



# Construction de l'executable : prime
# qui dépend de nbprem.o et maillon.o
# => Edition de lien entre les differents modules obj (.o)
prime:  nbprem.o maillon.o			# dependances
	gcc nbprem.o maillon.o -lm -o prime	# construction

# Construction du module objet : nbprem.o
# qui depend de nbprem.c et maillon.h
nb_prem.o: nbprem.c maillon.h			# dependances
	gcc -c nbprem.c 			# construction

# Construction du module objet : maillon.o
# qui depend de maillon.c et maillon.h
maillon.o: maillon.c maillon.h			# dependances
	gcc -c maillon.c   			# construction

# Pour effacer tous les fichiers temporaires de la compilation (.o)
# faites make clean
clean: 					# pas de dependances
	rm nbprem.o maillon.o 		# effacer *.o 

