# ROOT_Learning

> A personal learning and research-preparation repository for **CERN ROOT**, C++, and particle-physics data analysis.

This repository records my step-by-step study of ROOT, from basic histograms and graphs to ROOT files, TTrees, STAR-style analysis, particle identification (PID), particle ratios, and efficiency correction. The project is gradually being organized in a research-oriented structure so that source code, analysis outputs, documentation, and future workflows remain separate and reproducible.

## 📁 Project Structure

The target structure is:

```text
ROOT_Learning/
├── lessons/                 # ROOT/C++ learning source code
│   ├── lesson01.C
│   ├── lesson02.C
│   └── ...
│
├── plots/                   # Generated PNG/PDF figures
│   ├── lesson01.png
│   ├── lesson02.png
│   └── ...
│
├── .github/
│   └── workflows/           # Automated GitHub workflows
│
├── LEARNING_PROGRESS.md     # Automatically maintained learning tracker
├── README.md
└── .gitignore
```

The repository is being migrated toward this structure while preserving the original lesson history. Binary outputs are handled separately from source code, and large ROOT data files remain excluded by `.gitignore`.

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
| 08 | ROOT functions and analysis output | `lesson08.C` |
| 09 | `TFile`: creating and reading ROOT files | `lesson09_createFile.C`, `lesson09_readFile.C` |
| 10 | `TTree`: creating and reading event data | `lesson10_createTree.C`, `lesson10_readTree.C` |
| 11 | STAR-style pT analysis and fitting | `lesson11createSTAR.C`, `lesson11analysisSTAR.C` |
| 12 | PID, normalization, π/K ratio and uncertainties | `lesson12_createPID.C`, `lesson12_analysisPID.C` |
| 13 | ROOT analysis practice | `lesson13.C` |
| 14 | ROOT analysis practice | `lesson14.C` |
| 15 | ROOT analysis practice | `lesson15.C` |
| 16 | Efficiency correction and weighted histograms | `lesson16_efficiency.C` |

## 🔬 Analysis Workflow

The later lessons increasingly follow a particle-physics analysis pattern:

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
Statistical uncertainties
   ↓
Physics interpretation
```

Current topics include:

- `TH1F`, `TGraph`, `TF1`
- `TFile` and `TTree`
- Event-by-event reading with `GetEntry()`
- Branch binding with `SetBranchAddress()`
- Kinematic selection using `pT` and `η`
- Transverse-momentum spectra
- Histogram fitting
- PID
- Raw and normalized π/K ratios
- Statistical histogram uncertainties
- Efficiency correction with weighted fills

## 📈 Learning Progress

The repository contains an automatically maintained progress report:

urlLEARNING_PROGRESS.mdhttps://github.com/zhoub3957-afk/ROOT_Learning/blob/main/LEARNING_PROGRESS.md

A GitHub Actions workflow scans the lesson source files whenever lesson macros change and updates the progress report. This provides a simple foundation for tracking the evolution from ROOT fundamentals toward research-oriented analysis topics.

## 🛠️ Environment

- macOS
- C++ / ROOT macros (`.C`)
- CERN ROOT 6.40.02
- VS Code
- Git / GitHub

## ▶️ Running a ROOT Macro

Check the installed ROOT version:

```bash
root-config --version
```

For a directly executable macro:

```bash
root lesson01.C
```

For a macro containing a named function:

```bash
root
```

```cpp
.x lesson12_analysisPID.C
```

Some later lessons depend on local ROOT data files that are intentionally not stored in this public repository. Those inputs must be generated locally or supplied separately before the corresponding analysis macro can run.

## 🔄 Git Workflow

Typical local workflow:

```bash
git pull
git add .
git commit -m "Describe the change"
git push
```

`git pull` synchronizes changes from GitHub; `git add`, `git commit`, and `git push` record and publish local work.

## 📦 Data and Reproducibility

Large ROOT data files are intentionally excluded from version control. The repository should contain source code, documentation, and representative outputs rather than large or restricted datasets.

> **Data note:** real experimental data, unpublished results, or collaboration-internal files should not be uploaded to a public repository unless their distribution is explicitly permitted.

For future research projects, input files, configuration parameters, analysis selections, and software versions should be documented so that results can be reproduced independently.

## 🎯 Future Direction

This is a learning and research-preparation project. Planned topics include:

- systematic uncertainty treatment
- acceptance and efficiency corrections
- more rigorous statistical error propagation
- multi-particle correlations
- fluctuation observables
- higher moments
- larger and more modular analysis projects

The long-term goal is to apply these skills to experimental high-energy and nuclear physics research.

## 📌 Status

**Learning project — continuously evolving.**

The code is not intended to represent production-level experimental software. Repository structure, documentation, validation, and reproducibility practices will be upgraded as the analysis becomes more sophisticated.
