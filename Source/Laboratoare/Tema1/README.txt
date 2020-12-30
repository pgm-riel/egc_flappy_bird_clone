MOISE PETRE-GABRIEL
331CB


Tema 1 - ECG


Proiectul este structurat in mai multe clase:
	- Tema1
	- Birds
	- Pipes
	- LettersNDigits
	- Background
	
Rolul claselor Birds, Pipes, LettersNDigits si Background este pentru desenarea si crearea meshelor.
Toate clasele folosesc aceeasi functie CreateMesh pentru crearea meshelor pe baza listei de puncte si triunghiuri;
	- Birds contine 3 functii pentru desenarea componentelor pasarii : corpul , aripa si ochiul:
				- CreateBody
				- CreateWing
				- CreateEye
	- Pipes contine 2 functii pentru desenarea pipe-ului superior si cel inferior:
				- CreateTopPipe
				- CreateBottomPipe
	- Background contine 3 functii pentru desenarea ground-ului, elementelor din cer si 
unor margini negre folosite pentru a incadra scena in momentul cand dimensiunile ferestrei jocului sunt modificate
				- CreateGround
				- CreateSky
				- CreateBlocks
	- LettersNDigits contine o functie pentru desenarea mesajului de "GAME OVER"
				- CreateLetters
				
In cadrul clasei Tema1 sunt definite mecanicile jocului si sunt randate si animate modelele
	
	In header-ul fisierului sunt definite variabilele principale:
		- matrici de Modelare
		- matricea de Vizualizare si structurile pt spatiul logic si cel real
		- instante ale claselor descrise mai sus, folosite pentru crearea meshelor
		- variabilele pentru pozitia pasarii si ale pipe-urilor
			- init_birdY, birdY
			- init_pipesX, pipesX_iter1, pipesX_iter2
		- variabile pentru descrierea gravitatiei si a vitezei obiectelor
			- acceleration, velocity, speedPipe
		- variabile pentru generarea in mod random a pipe-urilor:
			- un vector de tupluri care contine seturi de valori ce reprezinta anumite pozitii ale pipe-urilor (pipesVars)
			- un vector (randomOrder) care e populat in mod random cu valori de la 0 la (nr max de seturi de valori - 1)
		- variabile bool pentru starea jocului:
			- running = jocul ruleaza
			- started = jocul a inceput
			- gameOver = jocul s-a sfarsit
			- paused = jocul e pus pe pauza
		- structuri pentru coliziuni ce vor fi initializate cu valorile maxime si minime de pe X si Y ale modelelor
			- BoxColl : botPip, upPip - ptr pipe-uri 
			- CircleColl : birp - ptr pasare
		- variabile pt scor
			- score, highscore
		- variabila pt a determina intervalul de pe oX in care trb sa se adauga un punct in momentul cand un pipe depaseste pasarea
			- wiggleRoom
		- variabile pentru scalarea marginilor negre cand se modifica dimensiunea ferestrei	
			- scaleFactorX, scaleFacorY
	
	Functionarea jocului:
		Jocul incepe la apasarea tastei SPACE, iar pentru a mentine pasarea in aer se apasa in mod repetat tasta SPACE.
		Prin apasarea tastei P, jocul se pune pe pauza, respectiv se scoate din pauza.
		Scopul jocului este acumularea a cat mai multe puncte, acest lucru avand loc daca pasarea ocoleste obstacolele.
		In cazul in care pasarea loveste un obstacol sau atinge solul, jocul se incheie (GAME OVER).
		In caz de GAME OVER, se apasa tasta ENTER pentru a face restart.
	
	Coliziunea dintr pasare si pipe-uri se realizeaza prin aplicarea metodei de coliziune dintre un cerc si un dreptunghi.
	La fiecare moment din joc se verifica daca se interesecteaza pasarea si topPipe, repsectiv bottomPipe, print intermediul functiei collision si
structurilor CircleColl birp, BoxColl upPip si botPip
	
	Rularea jocului incepe prin apelarea functiei Init() unde:
		- se initilizeaza camera
		- se seteaza spatiul logic
		- se initilizeaza variabile importante ( var pt starea jocului, acceleration, etc.)
		- se creaza meshele pt pasare, pipe-uri, background, mesajul "GAME OVER"
		- se populeaza vectorul randomOrder

	In functia Update(deltaTimeSeconds), apelata continuu cat timp jocul e pornit
		- se seteaza fereastra jocului(SetViewportArea) si se calculeaza matricea de Vizualizare (visMatrix)
		- se apeleaza DrawScene(visMatrix, deltaTimeSeconds), unde sunt randate modelele in scena, si are loc logica efectiva a jocului
	
	DrawScene(visMatrix, deltaTimeSeconds)
		
		- sunt randate ground-ul, sky-ul, marginile de incadrare a scenei, pasarea si pipe-urile
		
		- in functie de starea curenta a jocului, se calculeaza vitezele si matricile modelelor
			- if running == true
				- se calculeaza vitezele pasarii(birdY) si pipe-urilor(pipesX_iter1, pipesX_iter2) in functie de velocity si acceleration
			- else if !paused
				- pipe-urile stau pe loc si se calculeaza matricile pt animatie de gameOver a pasarii( birdMatrix, wingMatrix), si se randeaza mesajul "GAME OVER"
			- if paused 
				- toate obiectele stau pe loc, au viteza = 0;
			- in timp ce gameOver != true, pasarii ii sunt aplicate diferite transformari pentru a ii da o miscare fluida
					- cu cat viteza de cadere creste, pasarea se inclina mai mult pana intr-un unghi maxim
					- cand pasarea se ridica, aceasta se inclina in sus
		
		- pentru a da impresia ca sunt un numar infinit de pipe-uri sunt folosite 2 for-uri
			- intr-un for sunt randate 4 pipe-uri
			- in celalalt for sunt randate 24 de pipe-uri, acestea fiind de 7 feluri luate din vectorul pipesVars, intr-o ordine aleatorie
			- in momentul in care ultimul pipe dintr-unul dintre seturi iese din scena prin stanga , pipe-urile din setul respectiv sunt randate in afara scenei in dreapta, urmand sa repete miscarea
			- de asemenea pt fiecare pipe, la fiecare moment de timp se verifica daca are loc coliziune cu pasarea prin functia collision
				- se verifica collision intre pasarea si pipe-ul superior si cel inferior
		
		- pentru a creste scorul, marginea cea mai din dreapta de pe oX a unui pipe trebuie sa depaseasca coordonata pe oX a pasarii
			- din cauza ca viteaza la care se misca afecteaza locatia efectiva unde sunt randate modelele, 
e posibil ca coordonata pe oX a pasarii si coordonata pe oX a pipe-ului sa nu se interesecteze,
asa ca se verifica de fapt ca coordonata pe oX a pipe-ului sa fie intr un interval definit practic ca fiind coordonata pe oX a pasarii - wiggleRoom, coordonata pe oX a pasarii

		- la anumite praguri de scor(28 si 56)
			viteza pipe-urilor creste la 2.f, respectiv 2.5f

	OnKeyPress(key, mods)
	
		- la apasarea tastei SPACE
			- in cazul care jocul nu a inceput ( started == false), atunci started = true
			- sau velocity primeste o valoare pozitiva, ridicand pasarea, iar unghiul de inclinatie al pasarii devine pozitiv
		
		- la apasarea tastei P
			- paused = !paused
		
		- la apasarea tastei ENTER
			- se apeleaza Restart()
	
	OnWindowResize()
	
		- in cazul in care fereastra isi schimba dimensiunile, atunci e setata din nou camera cu noile dimensiuni si e recalculata visMatrix