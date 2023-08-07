<div align="center">
  <h1>Códigos-fonte de inteligência artificial</h1>
  <p>Alguns dos algoritmos usados para resolver problemas de busca da inteligência artificial</p>
  <hr>

  Nome do arquivo | Descrição
  ---|---
  caixeiro_viajante.cpp | Um caixeiro viajante precisa visitar 10 cidades do interior de Pernambuco. Ele pede a um agente de busca que determine uma rota para sua visita tal que cada cidade só seja visitada uma única vez, e ele percorra o menor espaço possível (em Km). O agente de busca tem um mapa do estado, e portanto sabe as distâncias entre as cidades. O algoritmo formula e implementa este problema em termos de estado inicial, estado final, operadores e função de avaliação para Busca por melhoras iterativas com Hill-Climbing.
  metro.c | Suponha que queremos construir um sistema para auxiliar um usuário do metrô de Paris a saber o trajeto mais rápido entre a estação onde ele se encontra e a estação de destino. O usuário tem um painel com o mapa, podendo selecionar a sua estação de destino. O sistema então acende as luzes sobre o mapa mostrando o melhor trajeto a seguir (em termos de quais estações ele vai atravessar, e quais as conexões mais rápidas a fazer – se for o caso). Considere que: <ul><li>a distância em linha reta entre duas estações quaisquer é dada em uma tabela (considerando 4 linhas).</li><li>a velocidade média de um trem é de 30km/h</li><li>tempo gasto para trocar de linha dentro de mesma estação (fazer baldeação) é de 4 minutos</li></ul>O algoritmo formula e implementa este problema em termos de estado inicial, estado final, operadores e função de avaliação para Busca heurística com o algoritmo A*.
  missionarios.cpp | Três missionários e três canibais estão em um lado do rio, juntamente com um barco que pode conter uma ou duas pessoas. O algoritmo descobre um meio de fazer todos atravessarem o rio, sem deixar que um grupo de missionários de um lado fique em número menor que o número de canibais nesse lado do rio. O algoritmo implementa e resolve o problema de forma ótima, utilizando o algoritmo de busca em largura.
  jogo-velha(pasta em python) | O algoritmo implementa o jogo da velha usando minimax (similar ao brute force, nesse caso, por testar todas as posições uma a uma e retornar a melhor).
</div>
<div align="center">
  OBS.: Os três primeiros algoritmos recebem os dados (estação de inicio/fim, por exemplo) direto no no código, portanto, se for necessário alterar esse formato para receber inputs será necessário atualizar o código, ou atualizar as variáveis no código para que elas busquem as soluções a partir de outros pontos.
</div>
