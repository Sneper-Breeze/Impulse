Сборка проекта осуществляется с помощью make файла.
После, для запуска программы нужно передать аргументами входной и выходной файлы, задержки на чтение, запись и перемещение головки ленты. 
Также для запуска вы можете использовать/подредактировать bash файл, в котором уже прописаны все изначальные аргументы.


В тексте задания было много недосказанностей, поэтому некоторые моменты я трактовал по своему. Ниже пояснения почему написано так.


1. Симуляция ленты выполнена не очень оптимизировано, так как по тексту задания показалось, что реализовать это можно как угодно, лишь бы просто сделать симуляцию,ещё и вставить задержки на работу. Поэтому симуляция такая, чтобы сэкономить время на написание кода.
2. По тексту задания я не очень понял насчет оперативной памяти, считать доп ленты оперативной памятью, или имеется ввиду реальная оперативная память, или всё сразу. Поэтому в алгоритме используется всего одна доп лента и всего пару переменных в функциях.
3. По причине памяти была выбрана сортировка вставками, да она работает за квадрат, но по доп памяти почти ничего не требует, а так как на память ограничение, это показалось оправдано. Плюс, на ленте это довольно легко реализуется.
