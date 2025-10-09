import os
import re

# --- CATEGORY MAPPING: folder name → total problems ---
CATEGORIES = {
    "01 Introductory Problems": 24,
    "02 Searching And Sorting": 35,
    "03 Dynamic Programming": 23,
    "04 Graph Algorithms": 36,
    "05 Range Queries": 25,
    "06 Tree Algorithms": 16,
    "07 Mathematics": 37,
    "08 String Algorithms": 21,
    "09 Geometry": 16,
    "10 Advanced Techniques": 25,
    "11 Sliding Window Problems": 11,
    "12 Interactive Problems": 6,
    "13 Bitwise Operations": 11,
    "14 Construction Problems": 8,
    "15 Advanced Graph Problems": 28,
    "16 Counting Problems": 18,
    "17 Additional Problems I": 30,
    "18 Additional Problems II": 30,
}

README_PATH = os.path.join(os.path.dirname(__file__), "README.md")


def count_solved(folder):
    """Return count of .cpp files inside folder."""
    try:
        return len([f for f in os.listdir(folder) if f.lower().endswith(".cpp")])
    except FileNotFoundError:
        print(f"⚠️ Folder not found: {folder}")
        return 0


def generate_progress_bar(solved, total, length=40):
    percent = (solved / total) if total else 0
    filled = int(round(length * percent))
    bar = "█" * filled + "." * (length - filled)
    return f"`[{bar}] {percent * 100:.1f}%`"


def update_readme(solved_map, total_solved, total_problems):
    with open(README_PATH, "r", encoding="utf-8") as f:
        content = f.read()

    # --- Create new progress table ---
    new_section = "## 🚀 My Progress\n\n"
    new_section += "| Category | Solved ✅ | Total 📄 | Completion 📈 |\n"
    new_section += "|-----------|-----------|-----------|----------------|\n"

    for cat, total in CATEGORIES.items():
        solved = solved_map.get(cat, 0)
        percent = int((solved / total) * 100) if total else 0
        new_section += f"| {cat} | `{solved}/{total}` | {total} | `{percent}%` |\n"

    new_section += f"\n📊 **Overall Progress: {total_solved} / {total_problems}**\n\n"
    new_section += generate_progress_bar(total_solved, total_problems) + "\n\n"
    new_section += "> This section is auto-updated using `update_readme.py`\n"

    # --- Replace existing progress section or insert new one ---
    pattern = r"## 🚀 My Progress[\s\S]*?(?=\n## |\Z)"
    if re.search(pattern, content):
        new_content = re.sub(pattern, new_section.strip() + "\n\n", content)
    else:
        # Insert after "## 📚 Table of Contents"
        insertion_point = content.find("## 📚 Table of Contents")
        if insertion_point != -1:
            insert_after = content.find("---", insertion_point)
            new_content = (
                content[: insert_after + 4]
                + "\n\n"
                + new_section.strip()
                + "\n\n"
                + content[insert_after + 4 :]
            )
        else:
            new_content = content + "\n\n" + new_section

    with open(README_PATH, "w", encoding="utf-8") as f:
        f.write(new_content)

    print("✅ README.md updated successfully!")


if __name__ == "__main__":
    base = os.path.dirname(__file__)
    solved_map = {}
    total_solved = 0

    for folder in CATEGORIES:
        path = os.path.join(base, folder)
        solved = count_solved(path)
        solved_map[folder] = solved
        total_solved += solved

    total_problems = sum(CATEGORIES.values())
    update_readme(solved_map, total_solved, total_problems)
