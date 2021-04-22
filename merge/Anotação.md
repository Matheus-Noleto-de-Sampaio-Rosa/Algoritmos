# Ideia central

  Imagine um vetor e você irá quebrar ele na metade e na menor das instâncias irá trocar as posições e depois nas maiores.
  Assim ainda está longe do pragmatismo dos códigos. Como assim quebrar no meio? onde vou guardar os valores?
  Criando 2 vetores em que um irá guardar n/2 valores e o outro n - n/2 valores.
  O motivo do segundo ser n - n/2 valores é por c tratar os inteiros com função piso se a quantidade de valores impar estariamos ignorando algum valor(provavelmente o ultimo)
  Após isso precisamos quebrar recursivamente bastando chamar a função para cada um dos vetores criados.
  Depois disso pode prosseguir o código.
  Imagine que você é o computador e cada um dos vetores lhe mostra um valor do inicio do seu vetor e você escolhe o menor deles e joga no lugar do seu primeiro vetor.
  (Como os valores estão salvos nos outros vetores criados pode substutuir no vetor primário mesmo.)
  Então após isso passa para a proxima posição do seu vetor primario e do vetor que você escolheu e executa o mesmo processo de escolha até que chegue ao fim de um dos subvetores.
  Como foi dito antes era até UM dos subvetores terminar. Então o resto do primeiro vetor não foi preenchido e nem o outro subvetor foi esvaziado.
  Jogue o resto do outro subvetor no vetor principal e pronto. Agora as outras chamadas irão terminar e estará ordenado.
