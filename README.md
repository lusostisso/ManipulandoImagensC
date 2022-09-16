# ManipulandoImagensC

Desenvolver um aplicativo para Windows, modo console, em linguagem C, que
implemente as seguintes funcionalidades:
- Abrir um arquivo no formato BMP selecionável pelo usuário
- Exibir as seguintes informações do arquivo:
- Tamanho da imagem (h x l)
- Profundidade de cores
- Se o arquivo não for BMP, exibir uma mensagem de erro.
- Gravar 3 arquivos, cada um com um canal de cor.
Gravar 3 arquivos, um somente com os componentes em vermelho, outro
em verde e o terceiro em azul, identificando os arquivos com um _R (ou
_G ou _B) ao final do nome do arquivo.
- Converter a imagem para o formato escala de cinza, gravando o arquivo com
a adição _gs ao nome.
No formato escala de cinza representamos o nível de luminância do
ponto; Para produzir uma imagem em escala de cinza usando formato
RGB, as três componentes de cor assumem o mesmo valor.
Duas opções:
- Media de R,G,B
- 30%R + 59%G +11% B
