import tkinter as tk
import time



def main():
    root = tk.Tk()
    root.title("Quiz Game")
    main_frame = tk.Frame(root)
    main_frame.pack(padx=480, pady=270)

    def clear_frame(frame):
        for widget in frame.winfo_children():
            widget.destroy()
    
    def typewriter_effect(label, text, index=0, delay=60):
        """
        Creates a typing effect for a Tkinter Label widget.

        Args:
            label (tk.Label): The Label widget to display the text.
            text (str): The full text to be typed.
            index (int): The current character index being displayed.
            delay (int): The delay in milliseconds between each character.
        """
        if index < len(text):
            label.config(text=text[:index+1])  # Update text with one more character
            label.after(delay, typewriter_effect, label, text, index + 1, delay)

 

    
    label = tk.Label(root, text="", font=("Arial", 20), fg="blue", wraplength=420)

    label.place(x=10, y=10)

    text_display_1 = "Hello There, This is a Quiz Game Do you want to Play The Game?"
    typewriter_effect(label, text_display_1)

    button_exit = tk.Button(root, text="No")
    button_play = tk.Button(root, text="Yes")

    button_play.place(x= 20, y= 90, width=25, command=)
    button_exit.place(x= 60, y= 90, width=25, command=exit())



    
    
    
    
  

    




    root.mainloop()

main()