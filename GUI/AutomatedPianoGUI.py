from pylab import *
from tkinter import *
from tkinter.ttk import *
from tkinter import messagebox
import time
import serial
import sys

ser = serial.Serial()
ser.baudrate = 9600
ser.port = 'COM4'
ser.open()
#print(ser)

counter = 0
paused = 1 # 1 = song is paused
currentSongLength = 0
startChar = None

window = Tk()
window.title("Hands of Beethoven")

window.geometry('650x450')

songNames = ["One More Light - Linkin Park","Mortal Kombat Theme Song","Secrets - One Republic","The Office Theme Song", "Heart and Soul - The Cleftones"]
songNamesXPosition = [320,320,335,333,320]
songPictures = ['one_more_light.png','mortal_kombat.png','secrets.png','the_office.png','heart_and_soul.png']
songLengths = [249,98,178,37,81]
startSongCharacters = ['l','m','s','o','h']
songlist = Listbox(window,width = 30,selectmode=SINGLE)
for song in songNames:
	songlist.insert(END,song)

progress = Progressbar(window,orient=HORIZONTAL,length=235,mode='determinate')
songlist.place(x = 0,y = 0)

def get_selection():
	global currentSongLength
	global startChar
	window.after(200, get_selection)
	temp = songlist.curselection() # returns tuple of which song in the list was selected
	if temp:
		song = temp[0] # first character in the tuple tells you which song is selected
		currentSongName = songNames[song]
		currentSongLength = songLengths[song]
		songPhoto = PhotoImage(file=songPictures[song])
		songNamePosition = songNamesXPosition[song]
		startChar = startSongCharacters[song]
		
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
		songLabel.configure(text = currentSongName)
		
		mins, secs = divmod(currentSongLength, 60)
		mins = round(mins)
		secs = round(secs)
		timeformat = '{:02d}:{:02d}'.format(mins, secs)
		lengthlabel['text'] = timeformat
	
def play_button():
	global paused
	paused = 0
	statusbar['text'] = "Playing music"
	if startChar == 'l':
		ser.write(b'l')
	elif startChar == 'm':
		ser.write(b'm')
	elif startChar == 's':
		ser.write(b's')
	elif startChar == 'o':
		ser.write(b'o')
	elif startChar == 'h':
		ser.write(b'h')
	count()
	
def count():
	global counter
	global currentSongLength
	if paused == 0: # song not paused
		if counter < currentSongLength:
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
	global counter
	global paused
	counter = 0
	paused = 1
	progress["value"]=counter
	progress.update()
	mins, secs = divmod(counter, 60)
	mins = round(mins)
	secs = round(secs)
	timeformat = '{:02d}:{:02d}'.format(mins, secs)
	currentTimelabel['text'] = timeformat
	currentTimelabel.after(1000,count)
	statusbar['text'] = "Music Stopped"
	ser.write(b'z')
	
def pause_button():
	global paused
	paused = 1 # song is paused
	statusbar['text'] = "Music Paused"
	ser.write(b'y')
	
canvas = Canvas(window, width = 250, height = 250)
canvas.place(x = 260,y = 5)

statusbar = Label(window, text="Select a song", relief=SUNKEN, anchor=W)
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

get_selection()
window.mainloop()
