GUI=gui
LOGIKA=logika
MAIN=main

# nazwa pliku wynikoweo
WYNIK=projektmvc

all: clean $(GUI).o $(LOGIKA).o $(MAIN).o $(WYNIK)
	@echo "Kompilacja zakonczona sukcesem!"

# modul GUI
$(GUI): 
	gcc -c $(GUI).c -o $(GUI).o

# modul LOGIKA
$(LOGIKA):
	gcc -c $(LOGIKA).c -o $(LOGIKA).o

# modul MAIN
$(MAIN):
	gcc -c $(MAIN).c -o $(MAIN).o

$(WYNIK): 
	gcc $(MAIN).o $(GUI).o $(LOGIKA).o -o $(WYNIK)

clean:

	@rm -f $(WYNIK) $(GUI).o $(LOGIKA).o $(MAIN).o

	@echo "Posprzatane!"
