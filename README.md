# ROOT_Learning

> A personal learning repository for CERN ROOT and particle-physics data analysis.

This repository records my step-by-step study of **ROOT**, with examples ranging from basic histogramming and graphing to ROOT files, TTrees, STAR-style data analysis, particle identification (PID), π/K ratios, and efficiency correction.

## 📚 Learning Roadmap

| Lesson | Main topic | Files |
|---|---|---|
| 01 | ROOT basics and first histogram | `lesson01.C` |
| 02 | Histogram operations and visualization | `lesson02.C` |
| 03 | Random numbers and Gaussian distributions | `lesson03.C` |
| 04 | `TGraph` and data/model visualization | `lesson04.C` |
| 05 | Function plotting and fitting concepts | `lesson05.C` |
| 06 | ROOT analysis practice | `lesson06.C` |
| 07 | ROOT analysis practice | `lesson07.C` |
| 08 | ROOT functions / analysis output | `lesson08.C`, `lesson08.pdf` |
| 09 | `TFile`: creating and reading ROOT files | `lesson09_createFile.C`, `lesson09_readFile.C` |
| 10 | `TTree`: creating and reading event data | `lesson10_createTree.C`, `lesson10_readTree.C` |
| 11 | STAR-style pT analysis | `lesson11createSTAR.C`, `lesson11analysisSTAR.C` |
| 12 | PID, normalization and π/K ratio | `lesson12_createPID.C`, `lesson12_analysisPID.C` |
| 13 | ROOT analysis practice | `lesson13.C` |
| 14 | ROOT analysis practice | `lesson14.C` |
| 15 | ROOT analysis practice | `lesson15.C` |
| 16 | Efficiency correction | `lesson16_efficiency.C` |

## 🔬 Current Topics

The later lessons begin to connect ROOT programming with particle-physics analysis concepts, including:

- `TFile` and `TTree`
- Event-by-event data reading with `GetEntry()`
- Track selection using kinematic cuts such as `pT` and `η`
- Transverse-momentum (`pT`) distributions
- Particle identification (PID)
- Histogram normalization
- Raw and normalized π/K ratios
- Statistical histogram uncertainties
- Efficiency correction and weighted histogram filling

## 📊 Analysis Outputs

The repository also contains selected plots and PDF outputs generated during the learning process. These outputs are kept together with the corresponding lessons so that the development of the analysis can be followed visually.

Large ROOT data files (`*.root`) are intentionally excluded through `.gitignore`. The repository therefore focuses on source code, documentation, and representative analysis outputs rather than large data files.

## 🛠️ Environment

- macOS
- C++ / ROOT macros (`.C`)
- CERN ROOT 6.40.02
- VS Code
- Git / GitHub

## ▶️ Running a ROOT Macro

After installing ROOT and opening a terminal in this repository, a macro can be executed with:

```bash
root lesson01.C
```

For a macro containing a function, ROOT can also be started interactively:

```bash
root
```

and then, for example:

```cpp
.x lesson12_analysisPID.C
```

The exact command may depend on how a macro is written and whether it defines a callable function.

## 🎯 Purpose

This repository is primarily a **learning and research-preparation record**. The goal is to gradually build practical skills in ROOT, C++, histogram analysis, and particle-physics data processing, with the longer-term aim of applying these skills to experimental high-energy/nuclear physics research.

## 📌 Note

The code is continuously evolving as new ROOT and particle-physics analysis topics are learned. Some early lessons are intentionally simple and may not follow the structure of production-level research software.
