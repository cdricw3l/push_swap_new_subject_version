# 🔀 Push Swap Sequence Generator

A browser-based tool to generate precise test sequences for the **push_swap** project at 42 School.  
No install, no server — just open and use.

---

## ✨ Features

- **Custom range** — set any Min / Max (e.g. `-500` to `3000`)
- **Custom count** — pick how many numbers to pull from that range
- **Exact disorder ratio** — slider from `0.01` to `1.00` with presets
- **Difficulty flags** — Simple / Medium / Complex (single select)
- **Full sequence output** — no `...` truncation, copy-ready
- **Live stats** — Count, Range, Target disorder, Actual disorder, Inversions
- **Command preview** — shows the full `./push_swap <args>` line

---

## 🚀 How to Use

1. Open `index.html` in any browser
2. Set your **Range Min** and **Range Max**
3. Set **How Many Numbers** to pick from that range
4. Select a **Difficulty** (only one can be active at a time)
5. Drag the **Disorder Ratio** slider or click a preset
6. Click **Generate Sequence**
7. Hit **Copy All** and paste into your terminal:

```bash
./push_swap <paste here>
```

---

## 🎯 Disorder Ratio

disorder = inversions / (n × (n−1) / 2)

| Ratio | Description |
|---|---|
| `0.05` | Almost sorted |
| `0.20` | Lightly shuffled |
| `0.50` | Half disordered |
| `1.00` | Fully reversed |

The generator uses the **adjacent swap method** — each swap adds exactly `+1` inversion, so your target ratio is always hit precisely.

---

## 🧪 Difficulty Presets

| Flag | Auto-fills Count | Grade target |
|---|---|---|
| 🟢 Simple | 5 | ≤ 12 moves |
| 🟡 Medium | 100 | ≤ 700 moves |
| 🔴 Complex | 500 | ≤ 5500 moves |

---

## 🛠 Tech

Pure **HTML + CSS + JavaScript** — zero dependencies, zero build steps.  
Works fully offline in any modern browser.

---

## 👤 Credit

Built by [Ahmad Kailany](https://ahmadkailany.com)