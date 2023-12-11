# s7-CD-LAB-ktu

## Experiments

This project is used by the following companies:

1.  Lexical Analyzer ( Token Identification ) using Company
2.  Lexical Analyzer using Lex tool
3.  Lex - Display the number of lines, words and characters in an input text
4.  Lex - Convert substring abc to ABC 
5.  Lex - Vowels and Consonants
6.  YACC - Valid Arithmetic Expression
7.  YACC - Valid Identifier
8.  YACC - Calculator
9.  e-closure of e-NFA
10. e-NFA to NFA conversion
11. NFA to DFA conversion
12. DFA Minimization
13. First & follow
14. Recursive Descent Parser
15. Constant Propogation
16. Intermediate Code Generation
17. Target Code Generation ( Backend of a compiler - Assembly language 8086)


## Running Tests

To run Lex files

```bash
  flex filename.l
  gcc lex.yy.c -o filename
  ./filename
```

To run YACC program ( + Lex)

```bash
  flex filename.l
  yacc -d filename.d
  gcc lex.yy.c y.tab.c -o filename
  ./filename
```


## Additional Programs

- C program to Remove comments
- YACC - Valid C Expression ( a = b + c ; )
- YACC - A^n B 
- YACC - Valid Loop and Conditional Statements 
        ( if-else : for : while : do-while : switch )

