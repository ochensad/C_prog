from tkinter import*
import ctypes

lib = ctypes.CDLL('./lib/libtask.dll')

fill_func = lib.fill_array_with_prime
fill_func.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int)
fill_func.restype = None

fill_add_func = lib.fill_narr_with_even_aft
fill_add_func.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int, ctypes.POINTER(ctypes.c_int), ctypes.c_int, ctypes.c_int)
fill_add_func.restype = ctypes.c_int

def fill_array_with_prime(size):

    array = (ctypes.c_int * size)()
    fill_func(array, size)
    return list(array)

def fill_narr_with_even_aft(arr_src, len_src, len_dst, number):

    arr_src = (ctypes.c_int * len_src)(*arr_src)
    arr_dst = (ctypes.c_int * len_dst)()
    counter = fill_add_func(arr_src, len_src, arr_dst, len_dst, number)
    
    if (counter > len_dst):
        arr_dst = (ctypes.c_int * counter)(*arr_dst)
        fill_add_func(arr_src, len_src, arr_dst, counter, number)
    return list(arr_dst)

def process_1():

    try:
        numb = int(entry_field_1.get())
    except:
        Message.showerror("Ошибка ввода", "Вы ввели невалидное количество элементов")
        return
    if (numb < 1):
        Message.showerror("Ошибка ввода", "Вы ввели невалидное количество элементов")
        return

    array = fill_array_with_prime(numb)
    str_arr = ' '.join(str(numb) for numb in array)
    output_field_1.delete(0, END)
    output_field_1.insert(0, str_arr)

def process_2():

    try:
        numb = int(entry_field_3.get())
    except:
        Message.showerror("Ошибка ввода", "Вы ввели невалидное число")
        return
    
    try:
        len_1 = int(entry_field_4.get())
    except:
        Message.showerror("Ошибка ввода", "Вы ввели невалидное число")
        return
    

    str_arr = entry_field_2.get()
    try:
        arr = [int(i) for i in str_arr.split()]
    except:
        Message.showerror("Ошибка ввода", "Вы ввели невалидное число")


    res_arr = fill_narr_with_even_aft(arr, len(arr), len_1, numb)
    str_arr = ' '.join(str(numb) for numb in res_arr)
    output_field_2.delete(0, END)
    output_field_2.insert(0, str_arr)


# Интерфейс
window = Tk()
window['bg'] = 'light blue'
window.title('Interface')
window.geometry('850x220')

txt_input_1 = Label(window, text = 'Кол-во элементов массива:', bg = 'white', font = 12)
txt_input_1.place(x = 20, y = 15, width = 270, height = 30)

entry_field_1 = Entry(window, width = 5, font = 12)
entry_field_1.place(x = 290, y = 15, width = 80, height = 30)

btn_fill_array_1 = Button(window, text = 'Вывести массив простых чисел', font = 12, activebackground = 'white', command = process_1)

btn_fill_array_1.place(x = 20, y = 75, width = 350, height = 30)

output_field_1 = Entry(window, width = 5, font = 12)
output_field_1.place(x = 20, y = 105, width = 350, height = 30)

txt_input_2 = Label(window, text = 'Заполните массив', bg = 'white', font = 12)
txt_input_2.place(x = 460, y = 15, width = 350, height = 30)

entry_field_2 = Entry(window, width = 35, font =  12)
entry_field_2.place(x = 460, y = 45, width = 350, height = 30)

txt_input_3 = Label(window, text = 'Вставляемое в массив число:', bg = 'white', font = 12)
txt_input_3.place(x = 460, y = 75, width = 270, height = 30)

entry_field_3 = Entry(window, width = 5, font = 12)
entry_field_3.place(x = 730, y = 75, width = 80, height = 30)

txt_input_4 = Label(window, text = 'Кол-во элементов в новом массиве:', bg = 'white', font = 12)
txt_input_4.place(x = 460, y = 105, width = 270, height = 30)

entry_field_4 = Entry(window, width = 5, font = 12)
entry_field_4.place(x = 730, y = 105, width = 80, height = 30)

btn_add_elem = Button(window, text = 'Вывести полученный массив', font = 12, activebackground = 'white', command = process_2)
btn_add_elem.place(x = 460, y = 135, width = 350, height = 30)

output_field_2 = Entry(window, width = 5, font = 12)
output_field_2.place(x = 460, y = 165, width = 350, height = 30)

window.mainloop()