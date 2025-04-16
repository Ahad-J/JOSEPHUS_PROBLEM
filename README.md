
<h1 align="center">⚔️ Josephus Problem Visualizer</h1>
<p align="center">
  <i>A visually interactive simulation of the classic Josephus Problem using C++ and SFML.</i>
</p>

---

## ✨ Features
<ul>
  <li>🌀 Circle-based simulation of the Josephus elimination process</li>
  <li>🎵 Background music and sound effects for immersive interaction</li>
  <li>🎮 Real-time graphical feedback using SFML sprites and animations</li>
  <li>⚰️ Red highlights and death texture for eliminated participants</li>
</ul>

---

## ⚙️ Technical Details

<table>
  <tr>
    <td><b>💻 Language</b></td>
    <td>C++</td>
  </tr>
  <tr>
    <td><b>🧰 Libraries</b></td>
    <td><a href="https://www.sfml-dev.org/">SFML</a> (Graphics, Audio)</td>
  </tr>
  <tr>
    <td><b>📦 Files</b></td>
    <td>Single file only – all logic included</td>
  </tr>
</table>

---

## 📂 Included Files

✅ One single `.cpp` file containing:
- Input handling for N and K  
- Implementation of the Josephus algorithm  
- SFML window setup and rendering  
- Texture, sound, and music management  
- Animation and elimination logic

> ❗️ Note: All required assets (images and sound files) are **not** included.


---

## 🕹 How to Use

1. Compile the file with SFML linked.
2. Provide:
   - `1.png` for alive sprite
   - `2.png` for dead sprite
   - `1.ogg` for background music(carol of the bells)
   - `1.wav` for sword slash sound
3. Run the program, enter values for N (people) and K (step).
4. Watch the simulation with real-time elimination.

### 🛠 Example Compilation:
```bash
g++ josephus.cpp -o josephus -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
```

---

## 🔁 Josephus Logic

- A random start is chosen from the N people.
- Every Kth person is removed until one survivor remains.
- The survivor is printed to the console.

---

## 📄 License

🆓 Open-source for learning and experimentation.  
📢 Please provide credit if reusing or modifying.

<p align="center"><b>⚔️ Animated with SFML and fueled by logic & C++</b></p>
