#Compilateur :

GCC = gcc

#==================== Paramètres de sortie ==========================
TARGET = calc
CSOURCES = calc analyseGrammaire calcerror calcul stack tokenizer option
REPINSTALL = /bin/
REPBACKUP = ./backup/

#========================= Flags ==========================
CCFLAGS = -g -O2 -pg
LDFLAGS = -lm

#=========================== Fichier sources =========================
SOURCEFILES = $(CSOURCES:=.c)
OBJECTFILES = $(CSOURCES:=.o)

# ---- compilation
$(TARGET):	$(OBJECTFILES)
	@echo "==== Linking ===="
	$(GCC) $(CCFLAGS) $(LDFLAGS) -o $(TARGET) $(OBJECTFILES)

.c.o:
	@echo "---- Compile : " $@ "----"
	$(GCC) $(CCFLAGS) -c -o $@ $<

depend:
	makedepend -D__c $(SOURCEFILES)

clean:
	rm -f *~ *.o $(TARGET) *.bak
cln:
	make clean
	rm -f core
	make depend

install:
	@echo "**** Installation ****"
	@cp  $(TARGET) $(REPINSTALL)

backup:
	@echo "//// Backup \\\\"
	cp -f *.[cChH] Makefile  $(REPBACKUP)
	
#************************ Makedepend écrit ici *************************
#
#Laisser une ligne blache après celle ci

# DO NOT DELETE

