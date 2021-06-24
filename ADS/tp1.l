/* Declarations */
%{
enum {
      LOOKUP = 0, /* default - looking rather than defining. */
      INT,
      FLOAT,
      DOUBLE,
      DEF
};

int state;
int add_count = 1000;

int add_word(int type, char *word);
int lookup_word(char *word);
%}
 
/* Rules */
%% 
[\n]   { state = LOOKUP; }   
      /* end of line, return to default state */
      /* whenever a line starts with a reserved keyword */
      /* start defining identifiers of that type */
[(]   { state = LOOKUP; }   
^int { state = INT; }
^float  { state = FLOAT; }
^double  { state = DOUBLE; }
^def { state = DEF; }

end {return 0;}

[0-9][a-zA-Z0-9_]*	/* ignore invalid identifiers */;

[a-zA-Z_][a-zA-Z0-9_]*/[(] {
	if(state != LOOKUP) {
                /* define the current lexeme */
                add_word(DEF, yytext);
      } 
}

[a-zA-Z_][a-zA-Z0-9_]* {
                /* identify lexeme, define it or look it up */
           if(state != LOOKUP) {
                /* define the current lexeme */
                add_word(state, yytext);
              } 
         }

.    /* ignore anything else */ ;
%%

/*** Main code ***/
int yywrap(){}

struct word *word_list; /* first element in word list */

/* define a linked list of words, their types, values and addresses */
struct word {
      char *word_name;
      int word_type;
      int word_address;
      struct word *next;
};

extern void *malloc() ;

int main(int argc, char **argv)
{ 
yylex();

struct word *wp = word_list;
printf("<--------------------Symbol Table-------------------->\nIdentifier\t\tAddress\t\tType\n");
/* display entire list i.e symbol table */
for(; wp; wp = wp->next) {
switch(wp->word_type) {
	case INT: printf("%s\t\t\t%d\t\tInteger\n", wp->word_name, wp->word_address); break;
         case FLOAT: printf("%s\t\t\t%d\t\tFloat\n", wp->word_name, wp->word_address); break;
         case DOUBLE: printf("%s\t\t\t%d\t\tDouble\n", wp->word_name, wp->word_address); break;
         case DEF: printf("%s\t\t%d\t\tFunction\n", wp->word_name, wp->word_address); break;
}
}

return 0;
} 

int add_word(int type, char *word)
{
      struct word *wp;

      if(lookup_word(word) != LOOKUP) {
            printf("!!! warning: identifier %s already defined \n", word);
            return 0;
      }

      /* identifier not there, allocate a new entry and link it on the list */

      wp = (struct word *) malloc(sizeof(struct word));

      wp->next = word_list;

      /* have to copy the indentifier itself as well */

      wp->word_name = (char *) malloc(strlen(word)+1);
      strcpy(wp->word_name, word);
      wp->word_type = type;
      add_count += 4;
      wp->word_address = add_count;
      word_list = wp;
      return 1;  
}

int lookup_word(char *word)
{
      struct word *wp = word_list;

      /* search down the list looking for the word */
      for(; wp; wp = wp->next) {
      if(strcmp(wp->word_name, word) == 0)
            return wp->word_type;
      }

      return LOOKUP;       /* not found */
}