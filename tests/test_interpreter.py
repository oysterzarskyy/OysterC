import shutil
import subprocess
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
BIN = ROOT / "build" / "oysterc"


class OysterCTest(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        cls.assertTool("gcc")
        subprocess.run(["gcc", "-std=c99", "-Wall", "-Wextra", "-O2", "-o", str(BIN), str(ROOT / "src" / "oysterc.c")], check=True)

    @staticmethod
    def assertTool(name: str) -> None:
        if shutil.which(name) is None:
            raise RuntimeError(f"required tool not found: {name}")

    def run_program(self, name: str) -> str:
        result = subprocess.run([str(BIN), str(ROOT / "examples" / name)], capture_output=True, text=True, check=True)
        return result.stdout

    def test_hello_world_example(self) -> None:
        output = self.run_program("hello.oy")
        self.assertIn("Hello, OysterC!", output)

    def test_file_io_example(self) -> None:
        output = self.run_program("file_io.oy")
        self.assertIn("wrote", output.lower())

    def test_ui_example(self) -> None:
        output = self.run_program("ui_app.oy")
        self.assertIn("window", output.lower())
        self.assertIn("oysterc-ui", output.lower())


if __name__ == "__main__":
    unittest.main()
