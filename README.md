# Push_Swap
Projet Push_Swap dans la branche Algo après ft_printf

Afin de l'utiliser, executer le fichier `test.sh` avec comme argument le nombre de chiffres a trier

Par exemple :
```
#bash
./test.sh 500
```

Retournera :
```
Sorting 500 integers 20 times:

 |   TEST  |  MOVES   |   STATE  |
 |    1    |  6555    |    OK    |
 |    2    |  6467    |    OK    |
 |    3    |  6463    |    OK    |
 |    4    |  6553    |    OK    |
 |    5    |  6571    |    OK    |
 |    6    |  6425    |    OK    |
 |    7    |  6491    |    OK    |
 |    8    |  6479    |    OK    |
 |    9    |  6458    |    OK    |
 |   10    |  6479    |    OK    |
 |   11    |  6504    |    OK    |
 |   12    |  6539    |    OK    |
 |   13    |  6527    |    OK    |
 |   14    |  6529    |    OK    |
 |   15    |  6387    |    OK    |
 |   16    |  6481    |    OK    |
 |   17    |  6600    |    OK    |
 |   18    |  6443    |    OK    |
 |   19    |  6460    |    OK    |
 |   20    |  6525    |    OK    |
 |-------------------------------|
 |   MIN   |   MEAN   |    MAX   |
>|   6387  |   6496   |    6600  |<
```

Afin d'utiliser le visu en python (fait par un autre eleve de 42) il faut installer python, puis utiliser la commande suivante :
```
python3 pyviz.py `ruby -e "puts (0..500).to_a.shuffle.join(' ')"`
```

Et modifier en consequence les nombres entre parenthese

Afin d'utiliser mon visu (plus basique) il faut appeler push_swap avec l'argument `-a`
