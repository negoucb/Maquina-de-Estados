
import unittest
from semaforo import Semaforo


class TestSemaforo(unittest.TestCase):

    # ==================================
    # 1. TESTES DE ESTADOS
    # ==================================

    def test_estado_inicial(self):
        semaforo = Semaforo()
        self.assertEqual(semaforo.obter_estado(), "Vermelho")

    def test_todos_os_estados(self):
        semaforo = Semaforo()

        estados = [
            "Vermelho",
            "Verde",
            "Amarelo"
        ]

        for estado in estados:
            semaforo.estado = estado
            self.assertEqual(semaforo.obter_estado(), estado)

    def test_estado_inicial_invalido(self):
        with self.assertRaises(ValueError):
            Semaforo("Azul")

    # ==================================
    # 2. TESTES DE TRANSICOES
    # ==================================

    def test_transicao_vermelho_verde(self):
        semaforo = Semaforo("Vermelho")
        self.assertEqual(semaforo.avancar(), "Verde")

    def test_transicao_verde_amarelo(self):
        semaforo = Semaforo("Verde")
        self.assertEqual(semaforo.avancar(), "Amarelo")

    def test_transicao_amarelo_vermelho(self):
        semaforo = Semaforo("Amarelo")
        self.assertEqual(semaforo.avancar(), "Vermelho")

    # ==================================
    # 3. TESTES DE CAMINHOS
    # ==================================

    def test_caminho_completo(self):
        semaforo = Semaforo()

        caminho_esperado = [
            "Verde",
            "Amarelo",
            "Vermelho"
        ]

        caminho_obtido = []

        for _ in range(3):
            caminho_obtido.append(semaforo.avancar())

        self.assertEqual(caminho_obtido, caminho_esperado)

    def test_repeticao_do_ciclo(self):
        semaforo = Semaforo()

        for _ in range(6):
            semaforo.avancar()

        self.assertEqual(semaforo.obter_estado(), "Vermelho")


# Executa os testes automaticamente
if __name__ == "__main__":
    unittest.main(verbosity=2)
