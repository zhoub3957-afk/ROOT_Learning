# ROOT_Learning

> A personal learning repository for **CERN ROOT**, C++, and particle-physics data analysis.

This repository records my step-by-step study of ROOT, starting from histograms and graphs and gradually moving toward ROOT files, TTrees, STAR-style analysis, particle identification (PID), particle-ratio studies, and efficiency correction.

The project is intentionally organized as a **learning record**: early lessons are simple demonstrations, while later lessons increasingly connect ROOT programming with the analysis workflow used in experimental high-energy and nuclear physics.

## 📚 Learning Roadmap

| Lesson | Main topic | Main files |
|---|---|---|
| 01 | First ROOT histogram | `lesson01.C` |
| 02 | Histogram operations and visualization | `lesson02.C` |
| 03 | Random numbers and Gaussian distributions | `lesson03.C` |
| 04 | `TGraph` and data/model visualization | `lesson04.C` |
| 05 | Function plotting / fitting | `lesson05.C` |
| 06 | ROOT analysis practice | `lesson06.C` |
| 07 | ROOT analysis practice | `lesson07.C` |
| 08 | ROOT functions and analysis output | `lesson08.C`, `lesson08.pdf` |
| 09 | `TFile`: creating and reading ROOT files | `lesson09_createFile.C`, `lesson09_readFile.C` |
| 10 | `TTree`: creating and reading event data | `lesson10_createTree.C`, `lesson10_readTree.C` |
| 11 | STAR-style pT analysis and fitting | `lesson11createSTAR.C`, `lesson11analysisSTAR.C` |
| 12 | PID, normalization, π/K ratio and uncertainties | `lesson12_createPID.C`, `lesson12_analysisPID.C` |
| 13 | ROOT analysis practice | `lesson13.C` |
| 14 | ROOT analysis practice | `lesson14.C` |
| 15 | ROOT analysis practice | `lesson15.C` |
| 16 | Efficiency correction and weighted histograms | `lesson16_efficiency.C` |

## 🔬 What I Am Learning

The current lessons cover several core ideas in particle-physics data analysis:

- ROOT histograms: `TH1F`
- Graphs and functions: `TGraph`, `TF1`
- ROOT files: `TFile`
- Event data: `TTree`
- Event-by-event reading with `GetEntry()`
- Branch binding with `SetBranchAddress()`
- Kinematic selection using `pT` and `η`
- Transverse-momentum (`pT`) spectra
- Histogram fitting
- Particle identification (PID)
- Histogram normalization
- Raw vs. normalized π/K ratios
- Statistical histogram uncertainties
- Efficiency correction using weighted fills

## 🧭 Analysis Concepts

The repository is also a record of the transition from **ROOT syntax** to **physics analysis thinking**.

For example, later lessons follow the approximate workflow:

```text
ROOT file
   ↓
TTree
   ↓
Event / track selection
   ↓
Histogram
   ↓
Normalization / fitting / ratio
   ↓
Efficiency correction
   ↓
Physics interpretation
```

The distinction between a raw ratio and a ratio of normalized spectra is kept explicitly in the PID analysis, because this is an important part of understanding histogram-based measurements.

## 📊 Analysis Outputs

Selected PNG and PDF files are kept with the learning code so that the development of the analysis can be followed visually.

Large ROOT data files are intentionally excluded from version control. The current `.gitignore` also excludes common ROOT/C++ build artifacts and macOS/editor temporary files.

> **Data note:** real experimental data, unpublished results, or collaboration-internal files should not be uploaded to a public repository unless their distribution is explicitly permitted.

## 🛠️ Environment

- macOS
- C++ / ROOT macros (`.C`)
- CERN ROOT 6.40.02
- VS Code
- Git / GitHub

## ▶️ Running a ROOT Macro

Open a terminal in the repository directory and make sure ROOT is available:

```bash
root-config --version
```

For a macro that can be executed directly:

```bash
root lesson01.C
```

For a macro containing a named function, start ROOT and execute it with:

```bash
root
```

```cpp
.x lesson12_analysisPID.C
```

Some later lessons depend on local ROOT data files that are intentionally not stored in this repository. Those files must be generated locally or supplied separately before the corresponding analysis macro can run.

## 🔄 Git Workflow

This repository is developed locally in VS Code and synchronized with GitHub using Git.

Typical workflow:

```bash
git add .
git commit -m "Describe the change"
git push
```

To obtain changes made on GitHub:

```bash
git pull
```

## 🎯 Purpose and Future Direction

This repository is primarily a **learning and research-preparation record**. The long-term goal is to build practical skills in ROOT, C++, statistical analysis, and particle-physics data processing that can be applied to experimental high-energy and nuclear physics research.

Future topics may include:

- more systematic histogram fitting
- statistical error propagation
- efficiency and acceptance corrections
- multi-particle correlations
- fluctuation observables
- higher moments
- larger and more structured analysis projects

## 📌 Status

**Learning project — continuously evolving.**

The code is not intended to represent production-level experimental software. As the analysis becomes more sophisticated, the repository structure, documentation, validation, and reproducibility practices will be upgraded accordingly.
