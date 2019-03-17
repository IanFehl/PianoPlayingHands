from tkinter import *
from tkinter.ttk import *
import time

window = Tk()
window.title("Piano Playing Hands")

window.geometry('650x450')

songNames = ["One More Light - Linkin Park","Mortal Kombat Theme Song","Dearly Beloved - Kingdom Hearts","Secrets - One Republic","The Office Theme Song"]
songNamesXPosition = [320,320,308,335,333]
songPictures = ['one_more_light.png','mortal_kombat.png','kingdom_hearts.png','secrets.png','the_office.png']
songLengths = [249,98,152,178,37]
songlist = Listbox(window,width = 30,selectmode=SINGLE)
for song in songNames:
	songlist.insert(END,song)

progress = Progressbar(window,orient=HORIZONTAL,length=235,mode='determinate')
songlist.place(x = 0,y = 0)

def get_selection():
	window.after(200, get_selection)
	temp = songlist.curselection() # returns tuple of which song in the list was selected
	if temp:
		song = temp[0] # first character in the tuple tells you which song is selected
		currentSongName = songNames[song]
		currentSongLength = songLengths[song]
		songPhoto = PhotoImage(file=songPictures[song])
		songNamePosition = songNamesXPosition[song]
		
		window.songPhoto = songPhoto
		canvas.create_image(20,20, anchor=NW, image=songPhoto)
		playButton.place_configure(x = 357, y = 300)
		stopButton.place_configure(x = 275, y = 300)
		pauseButton.place_configure(x = 439,y = 300)
		progress.place_configure(x = 278, y = 270)
		progress["maximum"]=currentSongLength
		songLabel.place_configure(x = songNamePosition,y = 0)
		lengthlabel.place_configure(x = 516,y = 272)
		currentTimelabel.place_configure(x = 245,y = 272)
		downloadButton.place_configure(x = 331, y = 380)
		songLabel.configure(text = currentSongName)
		
		mins, secs = divmod(currentSongLength, 60)
		mins = round(mins)
		secs = round(secs)
		timeformat = '{:02d}:{:02d}'.format(mins, secs)
		lengthlabel['text'] = timeformat
		
counter = 0
def play_button():
	paused = 0
	counter = 0
	statusbar['text'] = "Playing music"
	count()
	
def count():
	global counter
	counter += 1
	progress["value"]=counter
	progress.update()
	mins, secs = divmod(counter, 60)
	mins = round(mins)
	secs = round(secs)
	timeformat = '{:02d}:{:02d}'.format(mins, secs)
	currentTimelabel['text'] = timeformat
	currentTimelabel.after(1000,count)
		
def stop_button():
    statusbar['text'] = "Music Stopped"
	
def pause_button():
	paused = 1
	statusbar['text'] = "Music Paused"
	
def download_button():
	statusbar['text'] = "Sending song data to MSP432"
	
canvas = Canvas(window, width = 250, height = 250)
canvas.place(x = 260,y = 5)

statusbar = Label(window, text="Press a button", relief=SUNKEN, anchor=W)
statusbar.place(x = 0,y = 425)

playButtonPhoto = PhotoImage(file='play.png')
playButton = Button(window, image=playButtonPhoto, command=play_button)

stopButtonPhoto = PhotoImage(file='stop.png')
stopButton = Button(window, image=stopButtonPhoto, command=stop_button)

pauseButtonPhoto = PhotoImage(file='pause.png')
pauseButton = Button(window, image=pauseButtonPhoto, command=pause_button)

songLabel = Label(window, relief=FLAT)

lengthlabel = Label(window)

currentTimelabel = Label(window, text='00:00')

downloadButton = Button(window, text = 'Download to MSP432',command = download_button)

get_selection()
window.mainloop()
