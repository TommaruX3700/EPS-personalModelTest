# EPS-personalModelTest
Repo for EPS model development only.

---

### Architecture:
- ./Documentation/: made with obsidian software
- ./extLibs/: imported code from external libraries
- ./headers/: directory where all .h/.hpp are stored
- ./src/: directory for .c/.cpp files

---

### Imported Libraries (with documentation):
- nlohmann/json.hpp : https://github.com/nlohmann/json/releases or https://json.nlohmann.me/ or https://github.com/nlohmann/json#examples

- rapidjson : https://github.com/miloyip/rapidjson/

---

### EPS_MODEL error codes:
- 3: senza pacchi //error code 3, nessun pacco in input // error code 3
- 2: con un pallet minuscolo (che non riesce a tenere nulla) //error code 2, pallet dimensione troppo piccola
- 11: info pallet corrotte 
- 10: RILEVATO PACCO SENZA ID REGISTRATO A SISTEMA 