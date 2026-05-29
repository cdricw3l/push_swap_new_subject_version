
    // ── State ──
    let genNums = '';   // full space-separated string — ALWAYS full, never truncated
    let curMode = 'basic';
    let activeFlags = new Set();

    // ── Inversion count O(n log n) ──
    function countInversions(arr) {
      let c = 0;
      function mg(a) {
        if (a.length <= 1) return a;
        const m = a.length >> 1, L = mg(a.slice(0, m)), R = mg(a.slice(m)), o = [];
        let i = 0, j = 0;
        while (i < L.length && j < R.length) {
          if (L[i] <= R[j]) o.push(L[i++]);
          else { o.push(R[j++]); c += L.length - i; }
        }
        while (i < L.length) o.push(L[i++]);
        while (j < R.length) o.push(R[j++]);
        return o;
      }
      mg(arr.slice()); return c;
    }

    // ── Disorder generation (adjacent-swap, exact) ──
    function genDisorder(size, ratio) {
      const arr = Array.from({ length: size }, (_, i) => i + 1);
      const tp = (size * (size - 1)) / 2;
      const ti = Math.floor(ratio * tp);
      if (ti <= 0) return arr;
      if (ti >= tp) return arr.slice().reverse();
      let ci = 0, att = 0, max = ti * 6 + size * 4;
      while (ci < ti && att < max) {
        const i = Math.floor(Math.random() * (size - 1));
        if (arr[i] < arr[i + 1]) { [arr[i], arr[i + 1]] = [arr[i + 1], arr[i]]; ci++; }
        att++;
      }
      for (let i = 0; i < size - 1 && ci < ti; i++)
        if (arr[i] < arr[i + 1]) { [arr[i], arr[i + 1]] = [arr[i + 1], arr[i]]; ci++; }
      return arr;
    }

    // ── Pick `count` random unique integers from [min, max] ──
    function pickRandom(min, max, count) {
      const rangeSize = max - min + 1;
      if (count >= rangeSize) {
        // use all values
        return Array.from({ length: rangeSize }, (_, i) => min + i);
      }
      // Fisher-Yates partial shuffle on the range
      const pool = Array.from({ length: rangeSize }, (_, i) => min + i);
      for (let i = 0; i < count; i++) {
        const j = i + Math.floor(Math.random() * (rangeSize - i));
        [pool[i], pool[j]] = [pool[j], pool[i]];
      }
      return pool.slice(0, count);
    }

   
    function multi_generation()
    {
      let min = -500;
      let max = 500;
      let count = 6;
      let ratio = 0.2;

      while(count <= 7)
      {
        let list = generate(min, max, count, ratio);
        count++;
        console.log(list)

      }


    }
    
    
    // ── Generate ──
    function generate(mn, mx, cnt, ratio) {

      // 1. Pick `cnt` unique values from [mn, mx]
      const picked = pickRandom(mn, mx, cnt);
      // 2. Sort them to get rank order
      const sorted = picked.slice().sort((a, b) => a - b);
      // 3. Generate disorder permutation of indices 0..cnt-1
      const perm = genDisorder(cnt, ratio);
      // 4. Map permutation indices to actual picked values
      // perm[i] is rank (1-based), so the value at position i = sorted[perm[i]-1]
      const result = perm.map(rank => sorted[rank - 1]);

      // 5. Compute actual disorder
      const tp = (cnt * (cnt - 1)) / 2;
      const actualInv = countInversions(perm);
      const actualDis = tp > 0 ? (actualInv / tp) : 0;

      // FULL sequence — no truncation
      genNums = result.join(' ');
      return(genNums)
    }



    function copyOutput() {
      if (!genNums) return;
      navigator.clipboard.writeText(genNums).then(() => {
        const b = document.getElementById('btn-copy-out');
        b.classList.add('copied');
        b.innerHTML = '<svg width="11" height="11" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2.5"><polyline points="20 6 9 17 4 12"/></svg>Copied!';
        showToast('Sequence copied');
        setTimeout(() => { b.classList.remove('copied'); b.innerHTML = '<svg width="11" height="11" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2"><rect x="9" y="9" width="13" height="13" rx="2"/><path d="M5 15H4a2 2 0 0 1-2-2V4a2 2 0 0 1 2 2v1"/></svg>Copy'; }, 2000);
      });
    }




   

    function copyCmd(i) {
      const cmds = document.getElementById('cmd-preview')._cmds;
      if (!cmds || !cmds[i]) return;
      navigator.clipboard.writeText(cmds[i]).then(() => {
        const b = document.getElementById('ccp-' + i);
        b.classList.add('copied');
        b.innerHTML = '<svg width="12" height="12" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2.5"><polyline points="20 6 9 17 4 12"/></svg>Copied!';
        showToast('Full command copied to clipboard');
        setTimeout(() => { b.classList.remove('copied'); b.innerHTML = '<svg width="12" height="12" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2"><rect x="9" y="9" width="13" height="13" rx="2"/><path d="M5 15H4a2 2 0 0 1-2-2V4a2 2 0 0 1 2 2v1"/></svg>Copy full'; }, 2000);
      });
    }

    function showToast(msg) {
      const t = document.getElementById('toast');
      t.textContent = msg; t.classList.add('show');
      setTimeout(() => t.classList.remove('show'), 2200);
    }


    multi_generation()