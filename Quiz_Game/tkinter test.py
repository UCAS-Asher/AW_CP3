import tkinter as tk

def clear_frame(frame):
    for widget in frame.winfo_children():
        widget.destroy()

#clear_screen = clear_frame(main_frame)

def typewriter_effect(label, text, index=0, delay=50):
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


def main():
    root = tk.Tk()
    root.title("Quiz Game")
    main_frame = tk.Frame(root)
    main_frame.pack(padx=480, pady=270)



    
    label = tk.Label(root, text="", font=("Arial", 20), fg="blue")
    label_2 = tk.Label(root, text="", font=("Arial", 16), fg="blue")

    label.place(x=10, y=10)

    text_display_1 = "Hello There, This is a Quiz Game"
    typewriter_effect(label, text_display_1)

    text_display_2 = "Do you want to Play The Game?"
    typewriter_effect(label, text_display_2)




    root.mainloop()

main()