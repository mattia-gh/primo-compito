#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *estrai(char *, char *);

int main(int argc, char *argv[]) {
	int i;
	char *stringaRichiesta, *cp4, *metodo;
    char *dato1, *dato2, *dato3, *dato4, *dato5;
	printf("Content-type:text/html\n\n");
    printf("<html>\n<head>\n");
    printf("<title>Risultati sondaggio</title>\n");
    printf("</head>\n\n<body>\n");
    
    stringaRichiesta = getenv("QUERY_STRING");
    metodo = getenv("REQUEST_METHOD");
    cp4 = getenv("CONTENT_LENGTH");
    
    if (!strcmp(metodo, "POST") ) {
        stringaRichiesta = malloc (atoi(cp4)+1);
	    fgets(stringaRichiesta,atoi(cp4)+1 ,stdin);
    }
    
    printf("<h2>RISULTATI DEL SONDAGGIO</h2><hr />\n");
    //printf("QS = %s<br />\n", stringaRichiesta);
    dato1 = estrai(stringaRichiesta, "nome");
    dato2 = estrai(stringaRichiesta, "cognome");
    
	if (strstr(stringaRichiesta, "luogo")!=NULL) {
    	dato3 = estrai(stringaRichiesta, "luogo");
	}
	else {
		dato3="";
	}
	if (strstr(stringaRichiesta, "giorni")!=NULL) {
    	dato4 = estrai(stringaRichiesta, "giorni");
	}
	else {
		dato4="";
	}
	if (strstr(stringaRichiesta, "mezzo")!=NULL) {
    	dato5 = estrai(stringaRichiesta, "mezzo");
	}
	else {
		dato5="";
	}
    
    if (strcmp(dato1, "")==0 || strcmp(dato2, "")==0 || strcmp(dato3, "")==0 || strcmp(dato4, "")==0 || strcmp(dato5, "")==0) {
    	printf("<p style=\"color: red;\">SONDAGGIO NON COMPILATO CORRETTAMENTE!!!<br />\n");
    	if (strcmp(dato1, "")==0) {
    		printf("NOME: non inserito<br />\n");
		}
		if (strcmp(dato2, "")==0) {
    		printf("COGNOME: non inserito<br />\n");
		}
		if (strcmp(dato3, "")==0) {
    		printf("LUOGO PREFERITO: non selezionato<br />\n");
		}
		if (strcmp(dato4, "")==0) {
    		printf("DURATA PREFERITA: non selezionata<br />\n");
		}
		if (strcmp(dato5, "")==0) {
    		printf("MEZZO PREFERITO: non selezionato<br />\n");
		}
    	printf("</p>\n");
	}
	
	else {
		printf("<p style=\"color: blue;\">Grazie %s, hai compilato il sondaggio correttamente!!!<br />", dato1);
		printf("</p>\n");
	}
	
	printf("NOME = %s<br />\n", dato1);
    printf("COGNOME = %s<br />\n", dato2);
    printf("LUOGO PREFERITO = %s<br />\n", dato3);
    printf("DURATA PREFERITA = %s<br />\n", dato4);
    printf("MEZZO PREFERITO = %s<br />\n", dato5);
    printf("</body>\n\n</html>");
    
    return 0;
}

char *estrai(char *stringa, char *chiave) {
    char *inizio, *nuovo, *fine;
    int tot;   
    inizio = strstr(stringa, chiave) + strlen(chiave) +1;
    if (inizio[0]=='&') {
    	return "";
	}
    fine = strchr(inizio, '&');
    tot = fine - inizio;
    nuovo = malloc(tot);
    strncpy(nuovo, inizio, tot);
    return nuovo;
}
