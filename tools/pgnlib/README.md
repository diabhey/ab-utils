# PGNLib: Portable Game Notation Validator

Thousands of Chess games are played every single day. Every game is recorded in a format known as PGN (Portable Game Notation). Find below the pgn for a game played in 1984,

```
[Event "Lloyds Bank op"]
[Site "London"]
[Date "1984.??.??"]
[Round "5"]
[White "Chandler, Murray G"]
[Black "Anand, Viswanathan"]
[Result "1-0"]
[WhiteElo "2540"]
[BlackElo "2345"]
[ECO "B66"]

1.e4 c5 2.Nf3 Nc6 3.d4 cxd4 4.Nxd4 Nf6 5.Nc3 d6 6.Bg5 e6 7.Qd2 a6 8.O-O-O h6
9.Be3 Be7 10.Be2 Bd7 11.f4 b5 12.Bf3 Rc8 13.Nb3 Na5 14.Nxa5 Qxa5 15.Kb1 b4
16.Ne2 Bc6 17.Ng3 O-O 18.Bd4 d5 19.e5 Ne4 20.Bxe4 dxe4 21.Qe2 Bd5 22.b3 f5
23.exf6 Bxf6 24.Bxf6 Rxf6 25.Rhf1 Rcf8 26.Qe3 Qc7 27.f5 Qb7 28.fxe6 Rxf1
29.Nxf1 Bxe6 30.Ng3 Bd5 31.Qc5 Bf7 32.Nf5 Qb5 33.Qxb5 axb5 34.Rd4 Re8 35.Ne3 Bg6
36.Rxb4 Rf8 37.Rxb5 Rf2 38.Rc5  1-0
```

This tool extracts the moves and validates 'N' such games. The main motivation behind building this tool is to use it as an input driver to a chess game engine.

## Prerequisites

This project was tested on,
* OS: Linux (Ubuntu 16.04 LTS)
* Compiler: g++ (version 7)
* CMake: Minimum version 3 (**required**)

## Compiling

Assuming one has checked out the repository,

Run the following command

```
./compile
```

The binaries will generated inside the *build/bin* directory.

## Program Execution

Once the project has been successully compiled, open a terminal and  run the following commands,

```
cd build/bin
```

Run the valiator,

```
./PgnLib <path to the pgn file>
```

Sample .pgn file can be found in the **data/** directory.

## Owner
* Abhimanyu Selvan (bigillu)
