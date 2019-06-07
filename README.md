# CoreWar

Corewar is about bringing “players” together around a “virtual machine”, which will load some “champions” who will fight against one another with the support of “processes”, with the objective being for these champions to stay “alive”.


Example of placing players in the “arena”:


![arena_example](/images/00_arena_example.png)


The processes are executed sequentially within the same virtual machine and memory space. They can therefore, among other things, write and rewrite on top of each others so to corrupt one another, force the others to execute instructions that can damage them. The game ends when all the processes are dead. The winner is the last player reported to be “alive”:


![winner_example](/images/01_winner_example.png)


This project consists of three distinctive parts:
* *The assembler*: the program that will compile champions and translate them from the language you will write them in (assembly language) into “Bytecode”.
* *The virtual machine*: the “arena” in which champions will be executed. It offers various functions, all of which will be useful for the battle of the champions.
* *The champion*: your own super powerful champion.
