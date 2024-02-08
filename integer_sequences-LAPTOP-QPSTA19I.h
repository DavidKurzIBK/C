// Präprozessor-Direktive #ifndef, was "if not defined" bedeutet. 
// überprüft, ob Makro-Symbol "INTEGER_SEQUENCES_H" nicht definiert ist. 
// Wenn Symbol nicht definiert, wird nachfolgende Code ausgeführt. 
// Dies verhindert, dass Inhalt der Header-Datei mehrmals eingefügt, wenn sie in mehreren Dateien verwendet wird.

#ifndef INTEGER_SEQUENCES_H
#define INTEGER_SEQUENCES_H // Makro-Symbol "INTEGER_SEQUENCES_H", um sicherzustellen, dass der Inhalt der Header-Datei nur einmal eingefügt 

int *fibonacci(int n); // deklariert fkt "fibonacci", die einen Integer-Wert n als Parameter akzeptiert und einen Zeiger auf ein Integer-Array zurückgibt. 
int *odd_numbers(int n); // deklariert fkt Namen "odd_numbers", die einen Integer-Wert n ungerade"-".
int *even_numbers(int n); // deklariert fkt Namen "even_numbers", "-" n gerade "-"
void print_integer_sequence(const int *sequence, int n); // deklariert fkt Namen "print_integer_sequence", die zwei Parameter: sequence: Zeiger auf konstantes Integer-Array, 
// n: Integer-Wert, Länge des Arrays angibt, Zahlenfolge auf der Konsole aus.

#endif // INTEGER_SEQUENCES_H // Zeile beendet die Präprozessor-Direktive #ifndef und markiert das Ende des Header-Datei-Inhalts.

