#### [[sceltaPacchiNesting.hpp]]

### Variabili:
```cpp
std::vector<Pack*> pacchiDaScegliere; //INPUT
std::vector<Pack*> pacchiScelti; //OUTPUT1
std::vector<Pack*> pacchiScartati; //OUTPUT2, pacchi da riutilizzare nel prossimo giro
```
--- 
### Documentazione:
* questo modulo si occupa di selezionare i pacchi che andranno "sortati"
* Dentro i moduli vanno definiti gli algoritmi stessi, definiti da INPUT e OUTPUT.
* Le varibili "rougue" vanno IL PIU possibile definite dentro i file "operation" (funzioni)