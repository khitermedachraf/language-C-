# Makefile du projet Tableau Dynamique Ordonné TDO / ESI 2019 / 1CPI / ALSDD 
# Sous Linux faites make pour compiler le tout et generer l'executable 'app'



# Construction de l'executable (app)
# => Edition de lien entre les differents modules obj (.o)
app: 	app.o tdo.o			# dependances
	gcc app.o tdo.o -o app		# construction

# Construction du module objet : app.o
# qui depend de app.c et tdo.h
app.o:	app.c tdo.h			# dependances
	gcc -c app.c 			# construction

# Construction du module objet : tdo.o
# qui depend de tdo.c et tdo.h
tdo.o: 	tdo.c tdo.h			# dependances
	gcc -c tdo.c   			# construction

# Pour effacer tous les fichiers temporaires de la compilation (.o)
# faites make clean
clean: 					# pas de dependances
	rm tdo.o app.o 			# effacer *.o 

