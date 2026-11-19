
class Semaforo:

    # Estados permitidos
    ESTADOS = ["Vermelho", "Verde", "Amarelo"]

    def __init__(self, estado_inicial="Vermelho"):

        # Verifica se o estado inicial é válido
        if estado_inicial not in self.ESTADOS:
            raise ValueError("Estado inválido")

        self.estado = estado_inicial

    # Retorna o estado atual
    def obter_estado(self):
        return self.estado

    # Realiza a transição para o próximo estado
    def avancar(self):

        if self.estado == "Vermelho":
            self.estado = "Verde"

        elif self.estado == "Verde":
            self.estado = "Amarelo"

        elif self.estado == "Amarelo":
            self.estado = "Vermelho"

        return self.estado
