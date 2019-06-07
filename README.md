# CoreWar

Corewar is about bringing “players” together around a “virtual machine”, which will load some “champions” who will fight against one another with the support of “processes”, with the objective being for these champions to stay “alive”.


The processes are executed sequentially within the same virtual machine and memory space. They can therefore, among other things, write and rewrite on top of each others so to corrupt one another, force the others to execute instructions that can damage them. The game ends when all the processes are dead. The winner is the last player reported to be “alive”.

This project consists of three distinctive parts:
* The assembler:
* The virtual machine:
* The champion:
