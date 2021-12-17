using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Game
{
    public partial class Form4 : Form
    {
        int width = 30;
        int height = 16;
        int offset = 30;
        bool isFirstClick = true;
        FieldButton[,] field;
        int cellsOpened = 0;
        int bombs = 0;
        int b = 99;
        public Form4()
        {
            InitializeComponent();
            StartPosition = FormStartPosition.CenterScreen;

        }

        private void Form4_Load(object sender, EventArgs e)
        {
            field = new FieldButton[width, height];
            GenerateField();
        }
        public void GenerateField()
        {
            Random random = new Random();
            while (bombs != 99)
                for (int y = 0; y < height; y++)
                {
                    for (int x = 0; x < width; x++)
                    {
                        FieldButton newButton = new FieldButton();
                        newButton.Location = new Point((x + 1) * offset, (y + 2) * offset);
                        newButton.Size = new Size(offset, offset);
                        newButton.isClickable = true;

                        if ((random.Next(0, 100) <= 20) && (bombs < 99) && (newButton.isBomb == false))
                        {
                            newButton.isBomb = true;
                            bombs++;
                        }
                        newButton.xCoord = x;
                        newButton.yCoord = y;
                        Controls.Add(newButton);
                        newButton.MouseUp += new MouseEventHandler(FieldButtonClick);
                        field[x, y] = newButton;
                    }
                }
        }
        void FieldButtonClick(object sender, MouseEventArgs e)
        {

            FieldButton clickedButton = (FieldButton)sender;
            if (e.Button == MouseButtons.Left && clickedButton.isClickable)
            {
                if (clickedButton.isBomb)
                {
                    if (isFirstClick)
                    {
                        clickedButton.isBomb = false;
                        isFirstClick = false;
                        bombs--;
                        OpenRegion(clickedButton.xCoord, clickedButton.yCoord, clickedButton);
                    }
                    else
                    {
                        Explode();
                    }

                }
                else
                {
                    EmptyFieldButtonClick(clickedButton);
                }
                isFirstClick = false;
            }
            if (e.Button == MouseButtons.Right)
            {
                clickedButton.isClickable = !clickedButton.isClickable;
                if (!clickedButton.isClickable)
                {
                    clickedButton.Text = "B"; b--;
                }
                else
                {
                    clickedButton.Text = ""; b++;
                }
                label1.Text = b.ToString();
            }
            CheckWin();
        }

        void Explode()
        {
            foreach (FieldButton button in field)
            {
                if (button.isBomb)
                {
                    button.Text = "*";
                }
            }
            MessageBox.Show("Вы проиграли :(");
            Application.Restart();
        }
        void EmptyFieldButtonClick(FieldButton clickedButton)
        {

            for (int y = 0; y < height; y++)
            {
                for (int x = 0; x < width; x++)
                {
                    if (field[x, y] == clickedButton)
                    {
                        OpenRegion(x, y, clickedButton);
                    }
                }
            }
        }

        void OpenRegion(int xCoord, int yCoord, FieldButton clickedButton)
        {
            Queue<FieldButton> queue = new Queue<FieldButton>();
            queue.Enqueue(clickedButton);
            clickedButton.wasAdded = true;//
            while (queue.Count > 0)
            {
                FieldButton currentCell = queue.Dequeue();
                OpenCell(currentCell.xCoord, currentCell.yCoord, currentCell);
                cellsOpened++;
                if (CountBombsAround(currentCell.xCoord, currentCell.yCoord) == 0)
                {
                    for (int y = currentCell.yCoord - 1; y <= currentCell.yCoord + 1; y++)
                    {
                        for (int x = currentCell.xCoord - 1; x <= currentCell.xCoord + 1; x++)
                        {
                            if (x == currentCell.xCoord && y == currentCell.yCoord)//
                            {
                                continue;
                            }
                            if (x >= 0 && x < width && y < height && y >= 0)
                            {
                                if (!field[x, y].wasAdded)
                                {
                                    queue.Enqueue(field[x, y]);
                                    field[x, y].wasAdded = true;
                                }
                            }
                        }
                    }
                }
            }
        }

        void OpenCell(int x, int y, FieldButton clickedButton)
        {
            int bombsAround = CountBombsAround(x, y);
            if (bombsAround == 0)
            {

            }
            else
            {
                clickedButton.Text = "" + bombsAround;
            }
            clickedButton.Enabled = false;
        }

        int CountBombsAround(int xCoord, int yCoord)
        {
            int bombsAround = 0;
            for (int x = xCoord - 1; x <= xCoord + 1; x++)
            {
                for (int y = yCoord - 1; y <= yCoord + 1; y++)
                {
                    if (x >= 0 && x < width && y >= 0 && y < height)
                    {
                        if (field[x, y].isBomb == true)
                        {
                            bombsAround++;
                        }
                    }
                }
            }
            return bombsAround;
        }

        void CheckWin()
        {
            int cells = width * height;
            int emptyCells = cells - bombs;
            if (cellsOpened >= emptyCells)
            {
                MessageBox.Show("Вы победили! :)");
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form2 newForm = new Form2();
            newForm.Show();
            this.Hide();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }
    }
}
