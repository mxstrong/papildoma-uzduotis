# Pasikartojantys žodžiai
Pasikartojančius žodžius, jų pasikartojimų kiekį ir nuorodas randanti programa.

Ši programa duotame tekstiniame faile randa nuorodas, pasikartojančius žodžius ir jų kartojimosi dažnį, bei išveda šiuos dalykus į tekstinius failus.

## Diegimo instrukcija:
1. Atsisiųskite norimą programos versiją iš „Releases“ skilties arba naudodami `git clone https://github.com/mxstrong/papildoma-uzduotis.git` nusikopijuokite kodą į pasirinktą aplanką.
2. Pasirinkite aplanką, kuriame yra jūsų norima versija ir jį atsidarykite komandinėje eilutėje.
3. Jei naudojate Windows OS, vietoj `make` visur galite naudoti `nmake`, kuris yra parsisiunčiamas kartu su Visual Studio arba Windows SDK, tereikia jį įtraukti į path. Taip pat galite naudoti ir `make` parsisiuntę Git Bash arba kitą aplinką, kuri palaiko Unix tipo komandas(reikės parsisiųsti ir įtraukti į path ir pačia `make` programą).
4. Unix sistemoje sukompiliuokite programą su Makefile naudodami komandą `make` (Reikalingas clang kompiliatorius, jei jo neturite, atsisiųskite iš https://releases.llvm.org/download.html arba nurodykite kitą kompiliatorių: `make CC='[Kompiliatoriaus pavadinimas]'`(pvz. `make CC='g++'`)).
5. Jei norite labiau optimizuotos programos versijos, praeitame žingsnyje naudokite `make CFLAGS="-03"` (vietoj -03 galite naudoti kitas optimizavimo vėlevėles, tokais kaip -01, -02, 0s (daugiau: https://clang.llvm.org/docs/CommandGuide/clang.html#code-generation-options).
6. Pasileiskite programą komandinėje eilutėje naudodami komandą: `./RepeatedWords`.

## Naudojimosi instrukcija:
1. Įveskite failo su jūsų tekstu pavadinimą.
2. Programa sukurs tris failus: wordCounts.txt, references.txt ir links.txt.
3. Besikartojančių žodžių kartojimosi dažnį rasite sukurtame faile wordCounts.txt
4. Eilutes kuriose buvo besikartojantys žodžiai rasite sukurtame faile references.txt
5. Nuorodas esančias jūsų tekste rasite faile sukurtame links.txt

## Versijų istorija:
### [Versija v1.0](https://github.com/mxstrong/papildoma-uzduotis/releases/tag/v1.0)
Pradinė veikianti programos versija, kuri leidžia rasti tekste pasikartojančius žodžius, jų dažnį, vietas tekste ir nuorodas.
