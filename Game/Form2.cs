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
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
            StartPosition = FormStartPosition.CenterScreen;
        }

        private void button2_Click(object sender, EventArgs e)
        {

            if (label1.Text == "Легкий") { label1.Text = "Тяжелый";}
            else if (label1.Text == "Средний")
            {
                label1.Text = "Легкий"; 
            }
            else if (label1.Text == "Тяжелый")
            {
                label1.Text = "Средний"; 
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (label1.Text == "Легкий") { label1.Text = "Средний"; }
            else if (label1.Text == "Средний")
            {
                label1.Text = "Тяжелый";
            }
            else if (label1.Text == "Тяжелый")
            {
                label1.Text = "Легкий";
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (label1.Text == "Легкий") {
                Form1 newForm = new Form1();
                newForm.Show();
                this.Hide();
            }
            else if (label1.Text == "Средний") {
               Form3 newForm = new Form3();
               newForm.Show();
                this.Hide();
            }
            else if (label1.Text == "Тяжелый") {
               Form4 newForm = new Form4();
                newForm.Show();
               this.Hide();
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Form5 newForm = new Form5();
            newForm.Show();
            this.Hide();
        }
    }
}
